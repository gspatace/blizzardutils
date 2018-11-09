include_directories("${PROJECT_SOURCE_DIR}/include")

add_definitions(-DBLIZZ_API_EXPORTS)

add_library(blizzapi SHARED term_mapper_accessor.cpp blizz_api_mapper.cpp)