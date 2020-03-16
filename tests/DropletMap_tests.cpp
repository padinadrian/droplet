/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/16
 */

/* ===== Includes ===== */
#include <gtest/gtest.h>
extern "C" {
    #include "DropletMap.h"
}

/* ===== Tests ===== */

TEST(Position, TileIsWall1)
{
    DropletMap map;
    unsigned char map_data[4] = {0, 0x10, 0x10, 0};
    map.map_data = +map_data;
    map.width = 2;
    map.height = 2;
    EXPECT_EQ(TileIsWall(&map, 0, 0), 0);
    EXPECT_EQ(TileIsWall(&map, 1, 0), 1);
    EXPECT_EQ(TileIsWall(&map, 0, 1), 1);
    EXPECT_EQ(TileIsWall(&map, 1, 1), 0);
}
