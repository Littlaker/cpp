cmake_minimum_required(VERSION 3.10)

project(module)

aux_source_directory(. MODULE_SRC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DMODULE_DLL -DDLL_EXPORTS -Wall -Werror -fPIC")
add_library(module SHARED ${MODULE_SRC})

install(TARGETS module DESTINATION  "${PROJECT_SOURCE_DIR}/../exe/lib")
install(FILES api.h module_api.h DESTINATION  "${PROJECT_SOURCE_DIR}/../exe/include")