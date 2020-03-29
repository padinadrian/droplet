/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/16
 */

/* ===== Includes ===== */
#include <gtest/gtest.h>
extern "C" {
    #include "Droplet.h"
    #include "data/maps/droplet_level1_bg.c"
}

/* ===== Tests ===== */

TEST(Position, DropletCheckMovement)
{
    // Initialize map
    DropletMap level1_map;
    level1_map.map_data = DropletBackgroundLevel1;
    level1_map.width = DropletBackgroundLevel1Width;
    level1_map.height = DropletBackgroundLevel1Height;

    // Droplet starting point on grid
    Position droplet_grid_pos = {1, 10};

    // Droplet can move right, but not up, down, or left
    EXPECT_TRUE(
        DropletCheckMovement(
            J_RIGHT,
            &droplet_grid_pos,
            &level1_map
        )
    );
    EXPECT_FALSE(
        DropletCheckMovement(
            J_UP,
            &droplet_grid_pos,
            &level1_map
        )
    );
    EXPECT_FALSE(
        DropletCheckMovement(
            J_DOWN,
            &droplet_grid_pos,
            &level1_map
        )
    );
    EXPECT_FALSE(
        DropletCheckMovement(
            J_LEFT,
            &droplet_grid_pos,
            &level1_map
        )
    );

}
