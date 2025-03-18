# CMake file for unit test executable
cmake_minimum_required(VERSION 3.5)
project(droplet)

# List unit test source files
add_executable(${PROJECT_NAME}_tests
    # Tests
    Droplet_tests.cpp
    BackgroundMap_tests.cpp
    Hitbox_tests.cpp
    Position_tests.cpp
    Utility_tests.cpp

    # Sources
    ../src/BackgroundMap.c
    ../src/Debug.c
    ../src/Hitbox.c
    ../src/Level.c
    ../src/LevelMenu.c
    ../src/Levels.c
    ../src/LevelSelector.c
    ../src/Position.c
    ../src/Sprites.c
    ../src/SpriteSquare16.c
    ../src/Utility.c
    ../src/objects/Droplet.c
    ../src/objects/Gate.c
    ../src/objects/Spider.c
    ../src/objects/Switch.c
    ../src/levels/Level1.c
    ../src/levels/Level2.c
    ../src/levels/Level3.c

    ../data/maps/droplet_level_menu_bg.c
    ../data/maps/droplet_level1_bg.c
    ../data/maps/droplet_level2_bg.c
    ../data/maps/droplet_level3_bg.c
    ../data/maps/droplet_splash_bg.c
    ../data/tiles/droplet_background_tiles.c
    ../data/tiles/droplet_level_menu_tiles.c
    ../data/tiles/droplet_splash_tiles.c
    ../data/tiles/droplet_sprites.c
)

# Add mock directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/..")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../src")
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
    COMMAND ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_tests
    DEPENDS ${PROJECT_NAME}_tests
)
