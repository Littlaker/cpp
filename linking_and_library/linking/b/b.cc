#include "b.h"
#include <string>
#include <stdio.h>
#include "app.h"

extern std::string g_str;
extern App app;

const std::string s_str = "libb_s_str";

void print_str_b()
{
    printf("[libb::print_str_b] g_str: %s, s_str: %s, app: %p\n", g_str.c_str(), s_str.c_str(), &app);
}