include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(itemEndpointBuilderTestser itemEndpointBuilderTestser.cpp)

target_link_libraries(itemEndpointBuilderTestser blizzapi)