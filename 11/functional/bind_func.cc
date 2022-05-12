#include <functional>
#include <stdio.h>

int func(int &a, int &b)
{
    b++;
    a++;
    printf("a(%p) %d, b(%p) %d\n", &a, a, &b, b);
    return a + b;
}

static int staticFunc(int &a, int &b)
{
    printf("a(%p) %d, b(%p) %d\n", &a, a, &b, b);
    return a + b;
}

void  bindWithCopy()
{
    int a = 0;
    int b = 0;
    
    auto bind_func = std::bind(func, a, b); // 绑定的是a和b的副本, 副本的生命周期和std::function的返回对象的生命周期相同
    int res = bind_func();
    printf("a(%p) %d, b(%p) %d, res %d\n\n", &a, a, &b, b, res);
}

void bindWithRef()
{
    int a = 0;
    int b = 0;

    auto bind_func = std::bind(func, std::ref(a), std::ref(b)); // 绑定的是a和b的引用
    int res = bind_func();
    printf("a(%p) %d, b(%p) %d, res %d\n\n", &a, a, &b, b, res);
}

void bindStaticFunc()
{
    int a = 0;
    int b = 0;
    auto bind_func = std::bind(staticFunc, a, std::ref(b));
    int res = bind_func();
    printf("a(%p) %d, b(%p) %d, res %d\n\n", &a, a, &b, b, res);
}

void bindFirstArg()
{
    int a = 0;
    int b = 0;
    auto bind_func = std::bind(func, a, std::placeholders::_1);
    int res = bind_func(b);
    printf("a(%p) %d, b(%p) %d, res %d\n\n", &a, a, &b, b, res);
}

void bindSecondArg()
{
    int a = 0;
    int b = 0;
    auto bind_func = std::bind(func, std::placeholders::_1, b);
    int res = bind_func(a);
    printf("a(%p) %d, b(%p) %d, res %d\n\n", &a, a, &b, b, res);
}


void callEmpty()
{
    try
    {
        std::function<void()> func;
        func();
    }
    catch(...)
    {
        printf("std::bad_function_call\n\n");
    }
}

int main(int argc, char** argv)
{
    bindWithCopy();
    bindWithRef();
    bindStaticFunc();

    bindFirstArg();
    bindSecondArg();

    callEmpty();
    return 0;
}
