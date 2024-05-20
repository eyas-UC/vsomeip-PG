project(vsomoeip-PG)

find_package(vsomeip REQUIRED)

add_executable(${PROJECT_NAME}_exec)
target_link_libraries(vsomeip::vsomeip)