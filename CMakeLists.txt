cmake_minimum_required(VERSION 3.12)

set (PROJECT_NAME design_patterns)
project(${PROJECT_NAME} C CXX)

set (ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)
set (C_CXX_FLAGS "${C_CXX_FLAGS} -g")
set (CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

find_package(Boost 1.65 REQUIRED COMPONENTS
            serialization)

add_subdirectory(builder)
add_subdirectory(factories)
add_subdirectory(prototype)
add_subdirectory(singleton)