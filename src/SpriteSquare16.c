/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/08
 */

/* ===== Includes ===== */
#include "SpriteSquare16.h"

/* ===== Functions ===== */

/**
 * Set tiles for a 16x16 sprite all at once.
 * Assumes tiles are continuous in the pattern: TL, BL, TR, BR
 */
void SetSpriteTileSquare16(
        SpriteSquare16* sprite,
        UINT8 top_left_tile)
{
    /* set_sprite_tile(<sprite_id>, <sprite_data_index>); */
    set_sprite_tile(sprite->top_left,     top_left_tile);
    set_sprite_tile(sprite->bottom_left,  top_left_tile + 1);
    set_sprite_tile(sprite->top_right,    top_left_tile + 2);
    set_sprite_tile(sprite->bottom_right, top_left_tile + 3);
}

/**
 * Move a 16x16 sprite all at once.
 */
void MoveSpriteSquare16(
        SpriteSquare16* sprite,
        UINT8 x_pos,
        UINT8 y_pos)
{
    /* set_sprite_tile(<sprite_id>, <sprite_data_index>); */
    move_sprite(sprite->top_left,     x_pos + 0, y_pos + 0);
    move_sprite(sprite->bottom_left,  x_pos + 0, y_pos + 8);
    move_sprite(sprite->top_right,    x_pos + 8, y_pos + 0);
    move_sprite(sprite->bottom_right, x_pos + 8, y_pos + 8);
}

/**
 * Scroll a 16x16 sprite all at once.
 */
void ScrollSpriteSquare16(
    SpriteSquare16* sprite,
    UINT8 x_scroll,
    UINT8 y_scroll)
{
    /* set_sprite_tile(<sprite_id>, <sprite_data_index>); */
    scroll_sprite(sprite->top_left,     x_scroll, y_scroll);
    scroll_sprite(sprite->bottom_left,  x_scroll, y_scroll);
    scroll_sprite(sprite->top_right,    x_scroll, y_scroll);
    scroll_sprite(sprite->bottom_right, x_scroll, y_scroll);
}