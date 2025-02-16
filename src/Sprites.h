/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-04-13
 */

#ifndef DROPLET_SPRITE_MANAGER_H
#define DROPLET_SPRITE_MANAGER_H

/* ===== Includes ===== */
#include <gb/gb.h>

/* ===== Data Types ===== */

// Operation for
typedef enum {
    FLIP_HORIZONTAL = S_FLIPX,
    FLIP_VERTICAL   = S_FLIPY,
    FLIP_BOTH       = S_FLIPX | S_FLIPY,
} FlipDirection;


/* ===== Functions ===== */

/**
 * Initialize the sprite counter to 0.
 */
void InitializeSpriteCounter();

/**
 * Set all the current sprites to empty and reset the counter.
 */
void ClearExistingSprites();

/**
 * Returns a semi-unique sprite ID.
 * This sprite ID is used by gb functions such as
 * set_sprite_tile and move_sprite to control sprites.
 */
UINT8 NewSpriteID();

/**
 * Move the sprite including the offset.
 */
void MoveSprite(UINT8 sprite_id, UINT8 x_pos, UINT8 y_pos);

/**
 * Flip the sprite horizontally or vertically.
 */
void FlipSprite(UINT8 sprited_id, FlipDirection direction);

#endif  /* DROPLET_SPRITE_MANAGER_H */