include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TARGET_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_executable(singleton ${TARGET_SOURCES})

target_link_libraries(
    singleton gtest
)

include(GoogleTest)
gtest_discover_tests(singleton)

add_subdirectory(dependency_injection)
add_subdirectory(monostate)
add_subdirectory(multiton)