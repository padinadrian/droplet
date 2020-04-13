/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

#ifndef DROPLET_LEVEL_H
#define DROPLET_LEVEL_H

/* ===== Includes ===== */
#include <gb/gb.h>
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
 * Load the level.
 */
inline void LoadLevel(Level* level_ptr)
{
    set_bkg_tiles(
        0,
        0,
        DropletBackgroundLevel1Width,
        DropletBackgroundLevel1Height,
        map_data
    );
}

/**
 * Check if Droplet has reached the end of the level.
 * Return 1 if the level is complete, otherwise 0.
 */
inline UINT8 IsLevelComplete(Position* droplet_pos_ptr, Level* level_ptr)
{
    droplet_pos_ptr->x == level_ptr->exit_pos.x;
    droplet_pos_ptr->y == level_ptr->exit_pos.y;
}


#endif  /* DROPLET_LEVEL_H */
