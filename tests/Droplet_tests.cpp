/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-16
 */

/* ===== Includes ===== */
#include <gtest/gtest.h>
extern "C" {
    #include "Level.h"
    #include "BackgroundMap.h"
    #include "objects/Droplet.h"
    #include "data/maps/droplet_level1_bg.c"
}

/* ===== Tests ===== */

TEST(Position, DropletCheckMovement)
{
    // Initialize map
    Level level;
    SetLevelBackground(
        &level,
        (UINT8 *)DropletBackgroundLevel1,
        DropletBackgroundLevel1Width,
        DropletBackgroundLevel1Height
    );

    // Droplet starting point on grid
    Position droplet_grid_pos = {1, 10};
    DropletInitialize(droplet_grid_pos);

    // Droplet can move right, but not up, down, or left
    EXPECT_TRUE(DropletCheckMovement(&level, J_RIGHT));
    EXPECT_FALSE(DropletCheckMovement(&level, J_UP));
    EXPECT_FALSE(DropletCheckMovement(&level, J_DOWN));
    EXPECT_FALSE(DropletCheckMovement(&level, J_LEFT));
}
