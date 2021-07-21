cmake_minimum_required(VERSION 3.12)

set (PROJECT_NAME design_patterns)
project(${PROJECT_NAME} C CXX)

set (ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)
set (C_CSS_FLAGS "${C_CXX_FLAGS} -g")
add_subdirectory(builder)