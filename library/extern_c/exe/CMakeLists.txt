cmake_minimum_required(VERSION 3.10)
project(main)

include_directories("${CMAKE_SOURCE_DIR}/include")

link_directories("${CMAKE_SOURCE_DIR}/lib")

link_libraries(module)

add_executable(main main.cc)







