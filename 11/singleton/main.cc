#include "singleton.h"

int main(int argc, char** argv)
{
    Singleton& instance = Singleton::getInstance();
    instance.printInfo();
    return 0;
}
