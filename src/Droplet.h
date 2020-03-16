/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/08
 */

#ifndef DROPLET_DROPLET_H
#define DROPLET_DROPLET_H

/* ===== Includes ===== */
#include "SpriteSquare16.h"
#include "DropletMap.h"

/* ===== Data Types ===== */

typedef struct {
    SpriteSquare16 sprite;
    Position pos;
    UINT8 squat_counter;
    UINT8 squatting;
    UINT8 facing_right;
    UINT8 pressed;
} DropletSprite;

/* ===== Functions ===== */

/**
 * Initialize Droplet sprite and data.
 */
void DropletInitialize(DropletSprite* droplet_ptr);

/**
 * Animate Droplet squatting when he is idle.
 * This function should be called once per game loop.
 */
void DropletAnimate(DropletSprite* droplet_ptr);

/**
 * Helper function - check edge detection before moving sprite.
 */
int DropletCheckMovement(
    UINT8 joypad_input,
    Position* cur_pos_ptr,
    DropletMap* map_ptr
);

/**
 * Initialize Droplet sprite.
 */
void MoveDroplet(
    DropletSprite* droplet_ptr,
    UINT8 direction,
    DropletMap* map_ptr
);



#endif  /* DROPLET_DROPLET_H */