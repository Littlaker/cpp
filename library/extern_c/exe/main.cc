#include "module_api.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    void* module = module_create_module("module_x", "1.0.0");

    char* name = module_get_name(module);
    if (name)
    {
        printf("name: %s\n", name);
        module_free_string(name);
    }

    char* version = module_get_version(module);
    if (version)
    {
        printf("version: %s\n", version);
        module_free_string(version);
    }

    module_destroy_module(module);
    return 0;
}