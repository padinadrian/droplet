/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/05/04
 */

#ifndef DROPLET_MOCK_GB_H
#define DROPLET_MOCK_GB_H

/*

This file is a mock of several GBDK functions and data
types. It is used to make Intellisense happy since it can't
find the actual definitions. It is also useful to get the
unit tests to build.

*/

/* ===== Includes ===== */
#include <stdint.h>

/* ===== Data Types ===== */

typedef uint8_t UINT8;
typedef uint16_t UINT16;

typedef enum {
    J_LEFT,
    J_RIGHT,
    J_UP,
    J_DOWN,
} MOCK_JOYPAD_DIRECTION;

/* ===== Functions ===== */

/* Initialize the sprite tile data in memory. */
static inline void set_sprite_data(
    UINT8 first_tile_index,
    UINT8 number_of_tiles,
    UINT8 tile_data[])
{
    // Nothing
}

/* Assign a tile (image) to a sprite index. */
static inline void set_sprite_tile(
    UINT8 sprite_index,
    UINT8 tile_index)
{
    // Nothing
}

/* Move a sprite to a designated location on-screen. */
static inline void move_sprite(
    UINT8 sprite_index,
    UINT8 x_pos,
    UINT8 y_pos)
{
    // Nothing
}

/* Move the sprite by a relative amount. */
static inline void scroll_sprite(
    UINT8 sprite_index,
    INT8 x_delta,
    INT8 y_delta)
{
    // Nothing
}

/* Sleep the processor for the given number of milliseconds. */
static inline void delay(int millis)
{
    // Nothing
}

#define SHOW_SPRITES (void)0
#define SHOW_BKG (void)0

#endif  /* DROPLET_MOCK_GB_H */
