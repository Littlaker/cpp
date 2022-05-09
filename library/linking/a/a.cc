#include "a.h"
#include <string>
#include <stdio.h>
#include "app.h"

extern std::string g_str;
extern App app;

const std::string s_str = "liba_s_str";

void print_str_a()
{
    printf("[liba::print_str_a] g_str: %s, s_str: %s, app: %p\n", g_str.c_str(), s_str.c_str(), &app);
}