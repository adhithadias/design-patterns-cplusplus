set(TARGET_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
set(TARGET_SOURCES2 ${CMAKE_CURRENT_SOURCE_DIR}/foo.cpp)

if(Boost_FOUND)
    include_directories($(Boost_INCLUDE_DIRS))
    add_executable(car_singleton ${TARGET_SOURCES})
    add_executable(foo ${TARGET_SOURCES2})
endif()
