cmake_minimum_required(VERSION 3.10)
project(concurrent)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -g")

find_package(Threads REQUIRED)

add_executable(blocked_producer_consumer blocked_producer_consumer.cc)

add_executable(notify_producer_consumer notify_producer_consumer.cc)
target_link_libraries(blocked_producer_consumer PUBLIC Threads::Threads)
target_link_libraries(notify_producer_consumer PUBLIC Threads::Threads)