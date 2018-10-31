include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable( itemsFarmer itemsfarmer.cpp)

target_link_libraries(App blizzapi)