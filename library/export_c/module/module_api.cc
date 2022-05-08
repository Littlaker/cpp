#include "module_api.h"
#include "module.h"
#include <string.h>

using namespace library;

static void module_print_info(void* ptr)
{
     if (!ptr)
    {
        return;
    }

    Module* module = static_cast<Module*>(ptr);
    if (!module)
    {
        return;
    }
        
    module->printModuleInfo();
}

void* module_create_module(const char* name, const char* version)
{
    if (!name || !version)
    {
        return NULL;
    }
    return new Module(name, version);
}

void module_destroy_module(void* ptr)
{
    if (!ptr)
    {
        return;
    }

    Module* module = static_cast<Module*>(ptr);
    if (!module)
    {
        return ;
    }

    module_print_info(ptr);
    
    delete module;
}

char* module_get_name(void* ptr)
{
    if (!ptr)
    {
        return NULL;
    }

    Module* module = static_cast<Module*>(ptr);
    if (!module)
    {
        return NULL;
    }
    
    return strdup(module->getModuleName().c_str());
}

char* module_get_version(void* ptr)
{
    if (!ptr)
    {
        return NULL;
    }    

    Module* module = static_cast<Module*>(ptr);
    if (!module)
    {
        return NULL;
    }

    return strdup(module->getModuleVersion().c_str());
}

void module_free_string(char* ptr)
{
    if (ptr)
    {
        free(ptr);
    }
}

