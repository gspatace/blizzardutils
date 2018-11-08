include_directories("${PROJECT_SOURCE_DIR}/include")

include_directories("D:/Home/gspatace/3rdparties/x86_64/gt/Debug/include")
link_directories("D:/Home/gspatace/3rdparties/x86_64/gt/Debug/lib")

add_executable(itemEndpointBuilderTestser itemEndpointBuilderTestser.cpp)
target_link_libraries(itemEndpointBuilderTestser blizzapi)

add_executable(itemBuilder_g itemEndpointBuilderTest_g.cpp)
target_link_libraries(itemBuilder_g blizzapi gmock_maind)

add_test( NAME itemBuilder_g WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/out" COMMAND itemBuilder_g)
