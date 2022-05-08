#include "singleton.h"
#include <stdio.h>

Singleton::Singleton()
{
    printf("Singleton, this: %p\n",this);
}

Singleton::~Singleton()
{
    printf("~Singleton, this: %p\n", this);
}

Singleton& Singleton::getInstance()
{
    // c++11 局部静态变量是线程安全的
    static Singleton instance;
    return instance;
}

void Singleton::printInfo() const
{
    printf("printInfo, this: %p\n", this);
}