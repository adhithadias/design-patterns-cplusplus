cmake_minimum_required(VERSION 3.12)

set (PROJECT_NAME design_patterns)
project(${PROJECT_NAME} C CXX)

set (ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)
set (C_CXX_FLAGS "${C_CXX_FLAGS} -g")
set (CMAKE_CXX_STANDARD 14)

add_subdirectory(builder)
add_subdirectory(factories)
add_subdirectory(prototype)
add_subdirectory(singleton)