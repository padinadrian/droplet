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

typedef int8_t INT8;
typedef uint8_t UINT8;
typedef int16_t INT16;
typedef uint16_t UINT16;

typedef enum {
    J_LEFT    = 0x01,
    J_RIGHT   = 0x02,
    J_UP      = 0x04,
    J_DOWN    = 0x08,
    J_A       = 0x10,
    J_B       = 0x20,
    J_START   = 0x40,
    J_SELECT  = 0x80,
} MOCK_JOYPAD_DIRECTION;

/* ===== Functions ===== */

/* Initialize the sprite tile data in memory. */
static inline void set_sprite_data(
    UINT8 first_tile_index,
    UINT8 number_of_tiles,
    UINT8 *tile_data)
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

/* Initialize the background tile data in memory. */
static inline void set_bkg_data(
    UINT8 first_tile_index,
    UINT8 num_tiles,
    UINT8* tile_data)
{
    // Nothing
}

/* Display a background image. */
static inline void set_bkg_tiles(
    UINT8 x_start,
    UINT8 y_start,
    UINT8 width,
    UINT8 height,
    UINT8* map_data)
{
    // Nothing
}

/* Wait until all buttons are released. */
void waitpadup();

/* Sleep the processor for the given number of milliseconds. */
static inline void delay(int millis)
{
    // Nothing
}

#define SHOW_SPRITES (void)0
#define SHOW_BKG (void)0
#define HIDE_SPRITES (void)0
#define HIDE_BKG (void)0

#endif  /* DROPLET_MOCK_GB_H */
