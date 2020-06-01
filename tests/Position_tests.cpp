/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/16
 */

/* ===== Includes ===== */
#include <gtest/gtest.h>
extern "C" {
    #include "Position.h"
}

/* ===== Tests ===== */

TEST(Position, GridPosToPixelPos1)
{
    Position grid_pos = {0, 0};
    GridPosToPixelPos(&grid_pos);
    EXPECT_EQ(grid_pos.x, 0);
    EXPECT_EQ(grid_pos.y, 0);
}

TEST(Position, GridPosToPixelPos2)
{
    Position grid_pos = {1, 10};
    GridPosToPixelPos(&grid_pos);
    EXPECT_EQ(grid_pos.x, 8);
    EXPECT_EQ(grid_pos.y, 80);
}

TEST(Position, GridPosToPixelPos3)
{
    Position grid_pos = {19, 17};
    GridPosToPixelPos(&grid_pos);
    EXPECT_EQ(grid_pos.x, 152);
    EXPECT_EQ(grid_pos.y, 136);
}