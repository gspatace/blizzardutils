include_directories("${PROJECT_SOURCE_DIR}/include")

include_directories("${GOOGLETEST_INC}")
link_directories("${GOOGLETEST_LIB}")

add_executable(itemEndpointBuilderTestser itemEndpointBuilderTestser.cpp)
target_link_libraries(itemEndpointBuilderTestser blizzapi)

add_executable(itemBuilder_g itemEndpointBuilderTest_g.cpp)
target_link_libraries(itemBuilder_g blizzapi gtest_maind gtestd)

add_test( NAME itemBuilder_g WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_SUBDIR}" COMMAND itemBuilder_g)
add_test( NAME ItemEndpointBuilder WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_SUBDIR}" COMMAND itemEndpointBuilderTestser)
