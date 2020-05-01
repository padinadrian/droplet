/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/08
 */

#ifndef DROPLET_SPRITE_SQUARE_16_H
#define DROPLET_SPRITE_SQUARE_16_H

/* ===== Includes ===== */
#include <gb/gb.h>

/* ===== Data Types ===== */

typedef struct {
    UINT8 top_left;
    UINT8 bottom_left;
    UINT8 top_right;
    UINT8 bottom_right;
} SpriteSquare16;

/* ===== Functions ===== */

/**
 * Set tiles for a 16x16 sprite all at once.
 * Assumes tiles are continuous in the pattern: TL, BL, TR, BR
 */
void SetSpriteTileSquare16(
    SpriteSquare16* sprite_ptr,
    UINT8 top_left_tile
);

/**
 * Move a 16x16 sprite all at once.
 */
void MoveSpriteSquare16(
    SpriteSquare16* sprite_ptr,
    UINT8 x_pos,
    UINT8 y_pos
);

/**
 * Scroll a 16x16 sprite all at once.
 */
void ScrollSpriteSquare16(
    SpriteSquare16* sprite_ptr,
    UINT8 x_scroll,
    UINT8 y_scroll
);


#endif  /* DROPLET_SPRITE_SQUARE_16_H */
