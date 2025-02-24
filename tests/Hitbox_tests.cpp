/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2025-02-23
 */

/* ===== Includes ===== */
#include <gtest/gtest.h>
extern "C" {
    #include "Hitbox.h"
}

/* ===== Tests ===== */

// Check if hitboxes are intersecting.
TEST(Hitbox, CheckCollision1)
{
    Hitbox a, b;
    a.tl.x = 0; a.tl.y = 0;
    a.br.x = 3; a.br.y = 3;
    b.tl.x = 1; b.tl.y = 1;
    b.br.x = 4; b.br.y = 4;
    EXPECT_EQ(CheckCollision(&a, &b), 1);
}

// Check if hitboxes are intersecting.
TEST(Hitbox, CheckCollision2)
{
    Hitbox a, b;
    a.tl.x = 0; a.tl.y = 0;
    a.br.x = 1; a.br.y = 1;
    b.tl.x = 3; b.tl.y = 3;
    b.br.x = 4; b.br.y = 4;
    EXPECT_EQ(CheckCollision(&a, &b), 0);
}

// Check if hitboxes are intersecting.
TEST(Hitbox, CheckCollision3)
{
    Hitbox a, b;
    a.tl.x = 3; a.tl.y = 3;
    a.br.x = 4; a.br.y = 4;
    b.tl.x = 1; b.tl.y = 1;
    b.br.x = 2; b.br.y = 2;
    EXPECT_EQ(CheckCollision(&a, &b), 0);
}

// Check if hitboxes are intersecting.
TEST(Hitbox, CheckCollision4)
{
    Hitbox a, b;
    a.tl.x = (14 << 3) +  1;  a.tl.y = (8 << 3) + 1;
    a.br.x = (14 << 3) + 14;  a.br.y = (8 << 3) + 14;
    b.tl.x = (16 << 3) -  2;  b.tl.y = (8 << 3) - 2;
    b.br.x = (16 << 3) +  9;  b.br.y = (8 << 3) + 9;
    EXPECT_EQ(CheckCollision(&a, &b), 0);

    a.tl.x += 1;
    a.br.x += 1;
    EXPECT_EQ(CheckCollision(&a, &b), 1);
}