cmake_minimum_required(VERSION 3.10)

project(compile_time)

link_libraries(a b)
link_directories("${PROJECT_SOURCE_DIR}/lib")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(compile_time main.cc str.cc)