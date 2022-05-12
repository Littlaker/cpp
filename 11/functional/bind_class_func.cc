#include <functional>
#include <cstdio>
#include "foo.h"

void bindWithClassStaticFunc()
{
    std::function<void ()> func = std::bind(&Foo::staticFunc);
    func();
}


void bindWithClassNonStaticFunc()
{
    std::function<void (int)> func;
    
    {
        Foo foo;
        func = std::bind(&Foo::publicFunc, &foo, 1);  // 绑定类的成员函数，必须绑定类对象的指针

        func(1);   
    }

    // func(1); // foo的生命周期已结束，但是func的生命周期尚未结束，在此调用会发生Segmentation fault (core dumped),
}


int main(int argc, char** argv)
{
    bindWithClassNonStaticFunc();
    printf("\n\n");
    bindWithClassStaticFunc();
    return 0;
}
