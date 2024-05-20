cmake_minimum_required(VERSION 3.15)
project("socket_example")
set(CMAKE_BUILD_TYPE DEBUG)
add_executable(ProcessA data_collector.cpp)

target_include_directories(ProcessA PRIVATE support)
target_link_libraries(ProcessA PRIVATE pthread vsomeip::vsomeip)
