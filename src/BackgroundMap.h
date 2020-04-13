/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

#ifndef DROPLET_DROPLET_MAP_H
#define DROPLET_DROPLET_MAP_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Position.h"

/* ===== Data Types ===== */

typedef struct {
    UINT8* map_data;
    UINT8 width;
    UINT8 height;
} BackgroundMap;

/* ===== Functions ===== */

/**
 * Set the background.
 */
void SetBackground(BackgroundMap* map_ptr);

/**
 * Check if a background tile is a wall.
 * Return 1 if the tile is a wall, 0 otherwise.
 */
UINT8 TileIsWall(BackgroundMap* map_ptr, UINT8 x, UINT8 y);

#endif  /* DROPLET_DROPLET_MAP_H */
