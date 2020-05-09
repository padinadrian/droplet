/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/13
 */

/* ===== Includes ===== */
#include "Sprites.h"
#include "SpriteTileIndex.h"

/* ===== Static Variables ===== */
static UINT8 sprite_counter = 0;

/* ===== Functions ===== */

/** Initialize the sprite counter to 0. */
void InitializeSpriteCounter()
{
    sprite_counter = 0;
}

/** Set all the current sprites to empty and reset the counter. */
void ClearExistingSprites()
{
    UINT8 id;
    for (id = 0; id < sprite_counter; ++id) {
        set_sprite_tile(id, SPRITE_NULL);
    }
    sprite_counter = 0;
}

/** Returns a semi-unique sprite ID. */
UINT8 NewSpriteID()
{
    return sprite_counter++;
}

/** Move the sprite including the offset. */
void MoveSprite(UINT8 sprite_id, UINT8 x_pos, UINT8 y_pos)
{
    move_sprite(sprite_id, x_pos + 8, y_pos + 16);
}
