#include <dlfcn.h>
#include <string>
#include <stdio.h>
#include "a.h"
#include "b.h"

extern std::string g_str;
const std::string s_str = "main_s_str";

void print_str()
{
    printf("[main::print_str] main: g_str %s, s_str %s\n", g_str.c_str(), s_str.c_str());
}

int main(int argc, char** argv)
{
    print_str();

    print_str_a();

    print_str_b();
    return 0;
}

/*
App::App
App::App
[main::print_str] main: g_str main_g_str, s_str main_s_str
[liba::print_str_a] g_str: main_g_str, s_str: liba_s_str, app: 0x7f6f073fb0e0
[libb::print_str_b] g_str: main_g_str, s_str: libb_s_str, app: 0x7f6f073fb0e0
App::~App
App::~App
free(): double free detected in tcache 2
Aborted (core dumped)
*/