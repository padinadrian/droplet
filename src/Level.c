/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

/* ===== Includes ===== */
#include "Level.h"
#include "Position.h"

/* ===== Functions ===== */

/** Set the level map data. */
void SetLevelBackground(
        Level* level_ptr,
        UINT8* map_data,
        UINT8 map_width,
        UINT8 map_height)
{
    level_ptr->level_map.map_data = map_data;
    level_ptr->level_map.width = map_width;
    level_ptr->level_map.height = map_height;
}

/** Check if Droplet has reached the end of the level. */
UINT8 IsLevelComplete(
        Level* level_ptr,
        Position* droplet_pos_ptr)
{
    return PositionCompare(
        droplet_pos_ptr,
        &(level_ptr->exit_pos)
    );
}
