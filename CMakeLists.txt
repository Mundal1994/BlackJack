cmake_minimum_required(VERSION 3.1)

project(blackjack)

add_compile_options(-std=c++17 -Wall -Wextra -Wpedantic -Wconversion -Wfatal-errors)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${sources})
