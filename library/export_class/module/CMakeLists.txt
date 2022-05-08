cmake_minimum_required(VERSION 3.10)

project(module)

aux_source_directory(. MODULE_SRC)

add_compile_options(-DMODULE_DLL)
add_compile_options(-DDLL_EXPORTS)
add_compile_options(-fvisibility=hidden)

add_library(module SHARED ${MODULE_SRC})

install(TARGETS module DESTINATION  "${PROJECT_SOURCE_DIR}/../exe/lib")
install(FILES api.h module.h DESTINATION  "${PROJECT_SOURCE_DIR}/../exe/include")