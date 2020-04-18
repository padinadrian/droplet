/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/13
 */

#ifndef DROPLET_SPRITE_COUNTER_H
#define DROPLET_SPRITE_COUNTER_H

/* ===== Includes ===== */
#include <gb/gb.h>

/* ===== Functions ===== */

/**
 * Returns a semi-unique sprite ID.
 * This sprite ID is used by gb functions such as
 * set_sprite_tile and move_sprite to control sprites.
 */
UINT8 GetSpriteID();

#endif  /* DROPLET_SPRITE_COUNTER_H */