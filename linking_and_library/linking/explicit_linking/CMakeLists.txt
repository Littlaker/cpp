cmake_minimum_required(VERSION 3.10)

project(runtime)

enable_testing()

link_libraries(dl)

add_executable(runtime main.cc str.cc)

