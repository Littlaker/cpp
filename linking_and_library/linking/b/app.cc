#include "app.h"
#include <string>

App::App()
    :ptr_(new int(0))
{
    printf("App::App\n");
}

App::~App()
{
    printf("App::~App\n");
    delete ptr_;
}

App app;