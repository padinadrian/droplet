/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-05-24
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include <stdio.h>
#include "LevelSelector.h"
#include "Sprites.h"
#include "SpriteTileIndex.h"

/* ===== Functions ===== */

/** Display the selector at the starting position. */
void InitializeSelector(LevelSelector* selector_ptr)
{
    selector_ptr->pos.x = 0;
    selector_ptr->pos.y = 0;

    selector_ptr->sprites[0] = NewSpriteID();
    selector_ptr->sprites[1] = NewSpriteID();
    selector_ptr->sprites[2] = NewSpriteID();
    selector_ptr->sprites[3] = NewSpriteID();
    selector_ptr->sprites[4] = NewSpriteID();
    selector_ptr->sprites[5] = NewSpriteID();

    set_sprite_tile(selector_ptr->sprites[0], SPRITE_LEVEL_SELECTOR_0);
    set_sprite_tile(selector_ptr->sprites[1], SPRITE_LEVEL_SELECTOR_1);
    set_sprite_tile(selector_ptr->sprites[2], SPRITE_LEVEL_SELECTOR_2);
    set_sprite_tile(selector_ptr->sprites[3], SPRITE_LEVEL_SELECTOR_3);
    set_sprite_tile(selector_ptr->sprites[4], SPRITE_LEVEL_SELECTOR_4);
    set_sprite_tile(selector_ptr->sprites[5], SPRITE_LEVEL_SELECTOR_5);

    move_sprite(selector_ptr->sprites[0], 16, 44);
    move_sprite(selector_ptr->sprites[1], 24, 44);
    move_sprite(selector_ptr->sprites[2], 32, 44);
    move_sprite(selector_ptr->sprites[3], 16, 52);
    move_sprite(selector_ptr->sprites[4], 24, 52);
    move_sprite(selector_ptr->sprites[5], 32, 52);
}

/**
 * Move the entire selector sprite (made up of 6 8x8 sprites).
 */
void ScrollSelectorSprites(LevelSelector* selector_ptr, INT8 x, INT8 y)
{
    scroll_sprite(selector_ptr->sprites[0], x, y);
    scroll_sprite(selector_ptr->sprites[1], x, y);
    scroll_sprite(selector_ptr->sprites[2], x, y);
    scroll_sprite(selector_ptr->sprites[3], x, y);
    scroll_sprite(selector_ptr->sprites[4], x, y);
    scroll_sprite(selector_ptr->sprites[5], x, y);
}

/**
 * Move the selector in the given direction.
 * If the movement is invalid (end of row/column)
 * this does nothing.
 */
void MoveSelector(LevelSelector* selector_ptr, UINT8 direction)
{
    if (J_RIGHT == direction) {
        if (selector_ptr->pos.x < 5) {
            selector_ptr->pos.x += 1;
            ScrollSelectorSprites(selector_ptr, 24, 0);
        }
    }
    else if (J_LEFT == direction) {
        if (selector_ptr->pos.x > 0) {
            selector_ptr->pos.x -= 1;
            ScrollSelectorSprites(selector_ptr, -24, 0);
        }
    }
    else if (J_DOWN == direction) {
        if (selector_ptr->pos.y < 4) {
            selector_ptr->pos.y += 1;
            ScrollSelectorSprites(selector_ptr, 0, 24);
        }
    }
    else if (J_UP == direction) {
        if (selector_ptr->pos.y > 0) {
            selector_ptr->pos.y -= 1;
            ScrollSelectorSprites(selector_ptr, 0, -24);
        }
    }
}

/**
 * Return the level number of the currently highlighted level.
 */
UINT8 SelectLevel(LevelSelector* selector_ptr)
{
    const UINT8 x = selector_ptr->pos.x;
    const UINT8 y = selector_ptr->pos.y;
    return (y * 6) + x;
}
