cmake_minimum_required(VERSION 3.31.6)

project(visualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_compile_options("-w")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
