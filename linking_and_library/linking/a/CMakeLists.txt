cmake_minimum_required(VERSION 3.10)

project(a)

aux_source_directory(. SRC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Werror -fPIC ")

add_library(a SHARED ${SRC})

install(TARGETS a DESTINATION "${PROJECT_SOURCE_DIR}/../runtime_linking/lib")
install(TARGETS a DESTINATION "${PROJECT_SOURCE_DIR}/../compile_time_linking/lib")
install(FILES a.h DESTINATION "${PROJECT_SOURCE_DIR}/../compile_time_linking/include")
