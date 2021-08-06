set(TARGET_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Foo.cpp
)

# add_library(
#     pimpllib
#     ${CMAKE_CURRENT_SOURCE_DIR}/pimpl.h
#     ${CMAKE_CURRENT_SOURCE_DIR}/pimpl.cpp
# )

add_executable(untitled ${TARGET_SOURCES})

# target_link_libraries(untitled PRIVATE pimpllib)