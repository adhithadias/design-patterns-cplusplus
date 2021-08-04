find_package(Boost 1.65 REQUIRED COMPONENTS
            serialization)

set(TARGET_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

if(Boost_FOUND)
    include_directories($(Boost_INCLUDE_DIRS))
    add_executable(main ${TARGET_SOURCES})
    target_link_libraries(main Boost::serialization)
endif()
