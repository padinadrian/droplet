/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

#ifndef DROPLET_LEVEL_H
#define DROPLET_LEVEL_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Droplet.h"
#include "Position.h"
#include "BackgroundMap.h"

/* ===== Data Types ===== */

typedef struct {
    BackgroundMap level_map;
    Position droplet_start_pos;
    Position exit_pos;
} Level;

/* ===== Functions ===== */

/**
 * Assigns the level map data to the level.
 */
void SetLevelBackground(
    Level* level_ptr,
    UINT8* map_data,
    UINT8 map_width,
    UINT8 map_height
);

/**
 * Loads the level:
 *  - Sets the background.
 *  - Moves the sprites to the starting locations.
 *  - Initializes Droplet and enemies.
 */
void LoadLevel(Level* level_ptr, Droplet* droplet_ptr);

/**
 * Checks if Droplet has reached the end of the level.
 * Return 1 if the level is complete, otherwise 0.
 */
UINT8 IsLevelComplete(
    Level* level_ptr,
    Position* droplet_pos_ptr
);


#endif  /* DROPLET_LEVEL_H */
