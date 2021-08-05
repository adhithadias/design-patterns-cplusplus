set(TARGET_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

if(Boost_FOUND)
    include_directories($(Boost_INCLUDE_DIRS))
    add_executable(prototype ${TARGET_SOURCES})
    target_link_libraries(prototype Boost::serialization)
endif()
