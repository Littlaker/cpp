cmake_minimum_required(VERSION 3.10)

project(b)

aux_source_directory(. SRC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Werror -fPIC ")

add_library(b SHARED ${SRC})

install(TARGETS b DESTINATION "${PROJECT_SOURCE_DIR}/../runtime_linking/lib")
install(TARGETS b DESTINATION "${PROJECT_SOURCE_DIR}/../compile_time_linking/lib")
install(FILES b.h DESTINATION "${PROJECT_SOURCE_DIR}/../compile_time_linking/include")
