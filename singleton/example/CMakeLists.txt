set(TARGET_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_executable(singleton ${TARGET_SOURCES})

target_link_libraries(
    singleton gtest
)

gtest_discover_tests(singleton)