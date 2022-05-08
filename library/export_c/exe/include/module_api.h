#ifndef MODULE_API_H
#define MODULE_API_H

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

MODULE_API  void* module_create_module(const char* name, const char* version);

MODULE_API void module_destroy_module(void* module);

MODULE_API char* module_get_name(void* module);

MODULE_API char* module_get_version(void* module);

MODULE_API void module_free_string(char* str);

#ifdef __cplusplus
}
#endif

#endif // !MODULE_API_H