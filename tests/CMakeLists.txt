# CMake file for unit test executable

# List unit test source files
add_executable(${PROJECT_NAME}_tests
    # Tests
    Position_tests.cpp
    DropletMap_tests.cpp

    # Sources
    ../src/Position.c
    ../src/Droplet.c
    ../src/DropletMap.c
    ../src/SpriteSquare16.c
)
set_target_properties(${PROJECT_NAME}_tests PROPERTIES LINKER_LANGUAGE CXX)

# Add mock directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/mock")

# Add dependent libraries
target_link_libraries(${PROJECT_NAME}_tests
    gtest
    gtest_main
    gmock
    gmock_main
    pthread
)

# Add a commmand to build and run tests
add_custom_target(run_${PROJECT_NAME}_tests
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}_tests
    DEPENDS ${PROJECT_NAME}_tests
)
