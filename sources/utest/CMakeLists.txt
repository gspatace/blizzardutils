include_directories("${PROJECT_SOURCE_DIR}/include")

include_directories("${GOOGLETEST_INC}")
link_directories("${GOOGLETEST_LIB}")

add_executable(itemEndpointBuilderTest_gtest itemEndpointBuilderTest_gtest.cpp)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
SET(EXTRALIBS "")
else()
SET(EXTRALIBS "pthread")
endif()

target_link_libraries(itemEndpointBuilderTest_gtest blizzapi gtest_maind gtestd "${EXTRALIBS}")

add_test( NAME itemEndpointBuilderTest_gtest WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_SUBDIR}" COMMAND itemEndpointBuilderTest_gtest)
