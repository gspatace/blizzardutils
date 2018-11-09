include_directories("${PROJECT_SOURCE_DIR}/include")

include_directories("${GOOGLETEST_INC}")
link_directories("${GOOGLETEST_LIB}")

add_executable(itemEndpointBuilderTest_gtest itemEndpointBuilderTest_gtest.cpp)
target_link_libraries(itemEndpointBuilderTest_gtest blizzapi gtest_maind gtestd)

add_test( NAME itemEndpointBuilderTest_gtest WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_SUBDIR}" COMMAND itemBuilder_g)
