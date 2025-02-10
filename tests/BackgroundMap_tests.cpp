/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-16
 */

/* ===== Includes ===== */
#include <gtest/gtest.h>
extern "C" {
    #include "BackgroundMap.h"
}

/* ===== Tests ===== */

TEST(Position, TileIsWall1)
{
    BackgroundMap map;
    Position p;
    unsigned char map_data[4] = {0, 0x10, 0x10, 0};
    map.map_data = +map_data;
    map.width = 2;
    map.height = 2;
    p.x = 0;
    p.y = 0;
    EXPECT_EQ(TileIsWall(&map, &p), 0);
    p.x = 1;
    EXPECT_EQ(TileIsWall(&map, &p), 1);
    p.y = 1;
    EXPECT_EQ(TileIsWall(&map, &p), 0);
    p.x = 0;
    EXPECT_EQ(TileIsWall(&map, &p), 1);
}
