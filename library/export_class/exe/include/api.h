#ifndef API_H
#define API_H

#if defined _WIN32 || defined __CYGWIN__
  #define API_IMPORT __declspec(dllimport)
  #define API_EXPORT __declspec(dllexport)
  #define API_LOCAL
#else
  #if __GNUC__ >= 4
    #define API_IMPORT __attribute__ ((visibility ("default")))
    #define API_EXPORT __attribute__ ((visibility ("default")))
    #define API_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define API_IMPORT
    #define API_EXPORT
    #define API_LOCAL
  #endif
#endif

#ifdef MODULE_DLL // 动态库
  #ifdef DLL_EXPORTS // 
    #define MODULE_API API_EXPORT
  #else
    #define MODULE_API API_IMPORT
  #endif 
  #define MODULE_LOCAL API_LOCAL
#else // 静态库
  #define MODULE_API
  #define MODULE_LOCAL
#endif

#endif // !API_H 
