#include <functional>
#include <cstdio>

struct Foo 
{
    Foo(int num) 
        : num_(num) 
    {

    }
    
    void print_add(int i) const 
    { 
        printf("%d \n", i + 1);    
    }

    int num_;
};
 
void print_num(int i)
{
    printf("%d \n", i);
}
 
struct PrintNum 
{
    void operator() (int i) const
    {
        printf("%d \n", i);
    }
};
 
int main()
{
    // 存储自由函数
    std::function<void(int)> f_display = print_num;
    f_display(-9);
 
    // 存储 lambda
    std::function<void()> f_display_42 = []() { 
        print_num(42); 
    };
    f_display_42();
 
    // 存储到 std::bind 调用的结果
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();
 
    // 存储到成员函数的调用
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);
 
    // 存储到数据成员访问器的调用
    std::function<int(Foo const&)> f_num = &Foo::num_;
    printf("num_: %d\n", f_num(foo));
 
    // 存储到成员函数及对象的调用
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo, _1);
    f_add_display2(2);
 
    // 存储到成员函数和对象指针的调用
    std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3);
 
    // 存储到函数对象的调用
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
 
    auto factorial = [](int n) {
        // 存储 lambda 对象以模拟“递归 lambda ”，注意额外开销
        std::function<int(int)> fac = [&](int n)  { 
            return (n < 2) ? 1 : n*fac(n-1); 
        };
        // note that "auto fac = [&](int n){...};" does not work in recursive calls
        return fac(n);
    };
    
    for (int i{5}; i != 8; ++i) 
    { 
        printf("%d != %d; \n", i,  factorial(i));
    }

    return 0;
}