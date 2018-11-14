include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable( itemsFarmer itemsFarmer.cpp)

target_link_libraries(itemsFarmer blizzapi)