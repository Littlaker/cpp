#include <dlfcn.h>
#include <string>
#include <stdio.h>

typedef void (*print_str_func)();

print_str_func print_str_a = nullptr;
print_str_func print_str_b = nullptr;

extern std::string g_str;
const std::string s_str = "main_s_str";

void print_str()
{
    printf("[main::print_str] main: g_str %s, s_str %s\n", g_str.c_str(), s_str.c_str());
}

void load_liba()
{
    printf("-----------------\n");
    void* handle = dlopen("../lib/liba.so", RTLD_NOW | RTLD_GLOBAL);
    if (!handle)
    {
        char* error = dlerror();
        printf("[load_liba] error %s\n",error);
        return;
    }

    print_str_a = (print_str_func)dlsym(handle, "print_str_a");
    if (!print_str)
    {
        char* error = dlerror();
        printf("[load_liba] %s\n",error);
        return;
    }

    if (print_str_a)
    {
        print_str_a();
    }

    printf("-----------------\n\n");
}

void load_libb()
{
    printf("-----------------\n");
    void* handle = dlopen("../lib/libb.so", RTLD_NOW | RTLD_GLOBAL);
    if (!handle)
    {
        char* error = dlerror();
        printf("[load_libb] %s\n",error);
        return;
    }

    print_str_b = (print_str_func)dlsym(handle, "print_str_b");
    if (!print_str_b)
    {
        char* error = dlerror();
        printf("[load_libb] %s\n",error);
        return;
    }

    if (print_str_b)
    {
        print_str_b();
    }
    printf("-----------------\n\n");
}


int main(int argc, char** argv)
{
    print_str();

    load_liba();

    load_libb();


    if (print_str_a)
    {
        print_str_a();
    }

    if (print_str_b)
    {
        print_str_b();
    }

    print_str();
    return 0;
}

/*
[main::print_str] main: g_str main_g_str, s_str main_s_str
-----------------
App::App
[liba::print_str_a] g_str: liba_g_str, s_str: liba_s_str, app: 0x7f4ee84670e0
-----------------

-----------------
App::App
[libb::print_str_b] g_str: libb_g_str, s_str: libb_s_str, app: 0x7f4ee84670e0
-----------------

[liba::print_str_a] g_str: libb_g_str, s_str: liba_s_str, app: 0x7f4ee84670e0
[libb::print_str_b] g_str: libb_g_str, s_str: libb_s_str, app: 0x7f4ee84670e0
[main::print_str] main: g_str main_g_str, s_str main_s_str
App::~App
App::~App
free(): double free detected in tcache 2
Aborted (core dumped)
*/