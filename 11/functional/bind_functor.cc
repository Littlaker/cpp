#include <functional>
#include <stdio.h>


class Functor
{
public:
    void operator() (int a)
    {
        printf("this %p a %d\n\n", this, a);
    }
};


int main(int argc, char** argv)
{
    Functor functor;
    auto func = std::bind(functor, 10);
    func();
    return 0;
}