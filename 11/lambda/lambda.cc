#include <cstdio>
#include <functional>

void cpatureRef()
{
    int a = 10;
    printf("a %d\n", a);

    auto func = [&] () {
        a++;
        printf("a %d\n", a);
    };
    func();

    printf("a %d\n\n", a);
}

void cpatureCopy()
{
    int a = 10;
    printf("a %d\n", a);

    auto func = [&] () {
        a++;
        printf("a %d\n", a);
    };
    func();

    printf("a %d\n\n", a);
}


class  Foo
{
public:
    Foo()
        :a_(new int(0))
    {
        printf("this %p a_ %d\n\n", this, *a_);
    }

    ~Foo()
    {
        printf("this %p a_ %d\n\n", this, *a_);
        if (a_)
        {
            delete a_;
            a_ = nullptr;
        }
    }

    std::function<void ()> func()
    {
        auto func = [this] () {
            this->privateFunc();
        };

        return func;
    }

private:
    void privateFunc()
    {
        printf("this %p a_ %d\n\n", this, *a_);
    }
    int* a_;
};

void captureThis()
{
    Foo* foo = new Foo;
    auto func = foo->func();
    func();

    delete foo;

    func();
}


int main(int argc, char** argv)
{

    cpatureCopy();
    cpatureRef();
    captureThis();
    return 0;
}