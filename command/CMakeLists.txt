set(TARGET_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_executable(command ${TARGET_SOURCES})

set(COMPOSIT_COMMAND_TARGET_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/composite_command.cpp)
add_executable(composite_command ${COMPOSIT_COMMAND_TARGET_SOURCES})

