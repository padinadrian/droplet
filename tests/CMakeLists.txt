# CMake file for unit test executable

# List unit test source files
add_executable(${PROJECT_NAME}_tests
    # Tests
    # Droplet_tests.cpp
    Utility_tests.cpp
    Position_tests.cpp
    BackgroundMap_tests.cpp

    # Sources
    ../src/Sprites.c
    ../src/Utility.c
    ../src/Droplet.c
    ../src/Position.c
    ../src/BackgroundMap.c
    ../src/SpriteSquare16.c
)

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
