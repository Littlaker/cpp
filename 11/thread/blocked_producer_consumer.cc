#include <thread>
#include <mutex>
#include <queue>
#include <sstream>
#include <chrono>

static int current = 0;
const int kMaxBuffer = 100;
std::queue<int> gBuffer;
std::mutex gMutex;

void produce()
{
    std::stringstream ss;
    ss << std::this_thread::get_id();
    printf("thread id(%s), %s\n", ss.str().c_str(), __func__);

    while (true)
    {
        gMutex.lock();

        if (gBuffer.size() < kMaxBuffer)
        {
            gBuffer.push(current);
            current++;
        }

        gMutex.unlock();
    }
}

void consume()
{
    std::stringstream ss;
    ss << std::this_thread::get_id();
    printf("thread id(%s), %s\n", ss.str().c_str(), __func__);

    while (true)
    {
        gMutex.lock();


        if (gBuffer.size() > 0)
        {
            int num = gBuffer.front();
            gBuffer.pop();
            
            printf("thread id(%s), num %d\n", ss.str().c_str(), num);
        }
        else
        {
            printf("thread id(%s), empty buffer\n", ss.str().c_str());
        }

        gMutex.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(2)); // 睡眠2s，以便其他线程也能获取锁
    }
}

// 阻塞型 生产者-消费者模式
// 缺点：会阻塞线程，使用全局互斥量，可能某个线程会一直获取锁，其他线程没法获取的情况

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