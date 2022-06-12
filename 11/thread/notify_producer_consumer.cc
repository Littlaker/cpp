#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>
#include <cstdio>
#include <sstream>

std::queue<int> gBuffer;
const int kMaxBuffer = 100;
static int current = 0;
std::mutex gMutex;
std::condition_variable gProduceCond;
std::condition_variable gConsumeCond;


// lock_guard是一个互斥量包装程序，它提供了一种方便的RAII（Resource acquisition is initialization ）风格的机制来在作用域块的持续时间内拥有一个互斥量。
// 创建即加锁，作用域结束自动析构并解锁，无需手工解锁
// 不能中途解锁，必须等作用域结束才解锁
// 不能复制

// unique_lock是一个通用的互斥量锁定包装器，它允许延迟锁定，限时深度锁定，递归锁定，锁定所有权的转移以及与条件变量一起使用。
// 创建时可以不锁定（通过指定第二个参数为std::defer_lock），而在需要时再锁定
// 可以随时加锁解锁
// 作用域规则同 lock_grard，析构时自动释放锁
// 不可复制，可移动
// 条件变量需要该类型的锁作为参数（此时必须使用unique_lock）

void produce()
{
    std::stringstream ss;
    ss << std::this_thread::get_id();
    printf("thread id(%s), %s\n", ss.str().c_str(), __func__);

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::unique_lock<std::mutex> lock(gMutex);

        gProduceCond.wait(lock, [] (){
            return gBuffer.size() < kMaxBuffer;
        });
        
        gBuffer.push(current++);
        
        gConsumeCond.notify_all();

        lock.unlock();
    }
}

void consume()
{
    std::stringstream ss;
    ss << std::this_thread::get_id();
    printf("thread id(%s), %s\n", ss.str().c_str(), __func__);

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::unique_lock<std::mutex> lock(gMutex);

        gConsumeCond.wait(lock, [] () {
            return gBuffer.size() > 0;
        });

        int num = gBuffer.front();
        gBuffer.pop();
        
        printf("thread id(%s), num %d\n", ss.str().c_str(), num);

        gProduceCond.notify_all();

        lock.unlock();
    }

}



int main(int argc, char** argv)
{
    std::thread producer(produce);
    std::thread consumer_1(consume);
    std::thread consumer_2(consume);
    std::thread consumer_3(consume);
    
    producer.join();
    consumer_1.join();
    consumer_2.join();
    consumer_3.join();
    return 0;
}