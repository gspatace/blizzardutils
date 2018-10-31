include_directories("${PROJECT_SOURCE_DIR}/include")

add_definitions(-DBLIZZ_API_EXPORTS)

add_library(blizzapi SHARED blizz_api_endpoint_builder.cpp blizz_api_mapper.cpp)