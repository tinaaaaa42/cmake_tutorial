add_library(libanswer STATIC answer.cpp)

target_include_directories(libanswer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Here libcurl should be private for libanswer
target_link_libraries(libanswer PRIVATE wolfram)
