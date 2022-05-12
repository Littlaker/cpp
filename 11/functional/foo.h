#ifndef FOO_H
#define FOO_H

#include <cstdio>

class Foo
{
public:
    Foo()
        :a_(new int(0))
    {
        printf("this %p Foo::Foo()\n", this);
    }

    ~Foo()
    {
        printf("this %p Foo::~Foo()\n", this);
        if (a_)
        {
            delete a_;
            a_ = nullptr;
        }

    }

    Foo(const Foo& rhs)
    {
        printf("this %p Foo::Foo(const Foo&)\n", this);
    }

    Foo(Foo& rhs)
    {
        printf("this %p Foo::Foo(const Foo&)\n", this);
        a_ = rhs.a_;
        rhs.a_ = nullptr;
    }

    static void staticFunc()
    {
        printf("Foo::staticFunc\n");
    }

    void publicFunc(int a)
    {
        (*a_) += a;
        printf("this %p Foo::publicFunc\n", this);
    }

    int* a_;
};

#endif //!FOO_H