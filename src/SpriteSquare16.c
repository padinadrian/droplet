/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-08
 */

/* ===== Includes ===== */
#include "SpriteSquare16.h"
#include "Sprites.h"

/* ===== Functions ===== */

/**
 * Initialize sprite IDs for a 16x16 sprite.
 */
void InitializeSpriteSquare16(SpriteSquare16* sprite_ptr)
{
    sprite_ptr->top_left = NewSpriteID();
    sprite_ptr->bottom_left = NewSpriteID();
    sprite_ptr->top_right = NewSpriteID();
    sprite_ptr->bottom_right = NewSpriteID();
}

/**
 * Set tiles for a 16x16 sprite all at once.
 * Assumes tiles are continuous in the pattern: TL, BL, TR, BR
 */
void SetSpriteTileSquare16(
        SpriteSquare16* sprite_ptr,
        UINT8 top_left_tile)
{
    /* set_sprite_tile(<sprite_id>, <sprite_data_index>); */
    // check if flipped
    UINT8 flags = get_sprite_prop(sprite_ptr->top_left);
    if ((flags & FLIP_HORIZONTAL) && (flags & FLIP_VERTICAL)) {
        // 3 1
        // 2 0
        set_sprite_tile(sprite_ptr->top_left,     top_left_tile + 3);
        set_sprite_tile(sprite_ptr->bottom_left,  top_left_tile + 2);
        set_sprite_tile(sprite_ptr->top_right,    top_left_tile + 1);
        set_sprite_tile(sprite_ptr->bottom_right, top_left_tile + 0);
    }
    else if (flags & FLIP_HORIZONTAL) {
        // 2 0
        // 3 1
        set_sprite_tile(sprite_ptr->top_left,     top_left_tile + 2);
        set_sprite_tile(sprite_ptr->bottom_left,  top_left_tile + 3);
        set_sprite_tile(sprite_ptr->top_right,    top_left_tile + 0);
        set_sprite_tile(sprite_ptr->bottom_right, top_left_tile + 1);
    }
    else if (flags & FLIP_VERTICAL) {
        // 1 3
        // 0 2
        set_sprite_tile(sprite_ptr->top_left,     top_left_tile + 1);
        set_sprite_tile(sprite_ptr->bottom_left,  top_left_tile + 0);
        set_sprite_tile(sprite_ptr->top_right,    top_left_tile + 3);
        set_sprite_tile(sprite_ptr->bottom_right, top_left_tile + 2);
    }
    else {
        // 0 2
        // 1 3
        set_sprite_tile(sprite_ptr->top_left,     top_left_tile + 0);
        set_sprite_tile(sprite_ptr->bottom_left,  top_left_tile + 1);
        set_sprite_tile(sprite_ptr->top_right,    top_left_tile + 2);
        set_sprite_tile(sprite_ptr->bottom_right, top_left_tile + 3);
    }
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
    MoveSprite(sprite->top_left,     x_pos    , y_pos    );
    MoveSprite(sprite->bottom_left,  x_pos    , y_pos + 8);
    MoveSprite(sprite->top_right,    x_pos + 8, y_pos    );
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

/**
 * Flip a 16x16 sprite horizontally.
 */
void FlipHorizontalSpriteSquare16(SpriteSquare16* sprite_ptr)
{
    FlipSprite(sprite_ptr->top_left, FLIP_HORIZONTAL);
    FlipSprite(sprite_ptr->top_right, FLIP_HORIZONTAL);
    FlipSprite(sprite_ptr->bottom_left, FLIP_HORIZONTAL);
    FlipSprite(sprite_ptr->bottom_right, FLIP_HORIZONTAL);

    UINT8 top_left = get_sprite_tile(sprite_ptr->top_left);
    SetSpriteTileSquare16(sprite_ptr, top_left);
}
