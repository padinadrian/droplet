/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-08
 */

/* ===== Includes ===== */
#include "SpriteSquare16.h"
#include "Sprites.h"

/* ===== Functions ===== */

/**
 * Set tiles for a 16x16 sprite all at once.
 * Assumes tiles are continuous in the pattern: TL, BL, TR, BR
 */
void SetSpriteTileSquare16(
        SpriteSquare16* sprite_ptr,
        UINT8 top_left_tile)
{
    /* set_sprite_tile(<sprite_id>, <sprite_data_index>); */
    set_sprite_tile(sprite_ptr->top_left,     top_left_tile);
    set_sprite_tile(sprite_ptr->bottom_left,  top_left_tile + 1);
    set_sprite_tile(sprite_ptr->top_right,    top_left_tile + 2);
    set_sprite_tile(sprite_ptr->bottom_right, top_left_tile + 3);
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
    MoveSprite(sprite->top_left,     x_pos + 0, y_pos + 0);
    MoveSprite(sprite->bottom_left,  x_pos + 0, y_pos + 8);
    MoveSprite(sprite->top_right,    x_pos + 8, y_pos + 0);
    MoveSprite(sprite->bottom_right, x_pos + 8, y_pos + 8);
}

/**
 * Scroll a 16x16 sprite all at once.
 */
void ScrollSpriteSquare16(
        SpriteSquare16* sprite,
        INT8 x_scroll,
        INT8 y_scroll)
{
    /* set_sprite_tile(<sprite_id>, <sprite_data_index>); */
    scroll_sprite(sprite->top_left,     x_scroll, y_scroll);
    scroll_sprite(sprite->bottom_left,  x_scroll, y_scroll);
    scroll_sprite(sprite->top_right,    x_scroll, y_scroll);
    scroll_sprite(sprite->bottom_right, x_scroll, y_scroll);
}