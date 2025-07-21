cmake_minimum_required (VERSION 3.25)
project (snake)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(snake src/Button.cpp src/main.cpp)

# target_include_directories(snake PRIVATE "${PROJECT_BINARY_DIR}")
target_include_directories(snake PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(snake sfml-graphics)
install(TARGETS snake DESTINATION bin)
