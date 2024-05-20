cmake_minimum_required(VERSION 3.24)
project(vsomoeip-PG)

find_package(vsomeip REQUIRED)

add_executable(${PROJECT_NAME}_exec)

add_subdirectory(code-base)