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

/**
 * Helper function - check edge detection before moving sprite.
 */
int DropletCheckMovement(
        Level* level_ptr,
        Droplet* droplet_ptr,
        UINT8 joypad_input)
{
    UINT8 x = droplet_ptr->pos.x;
    UINT8 y = droplet_ptr->pos.y;
    BackgroundMap* map_ptr = &(level_ptr->level_map);
    switch (joypad_input)
    {
        case J_LEFT:
            return !(
                TileIsWall(map_ptr, x - 1, y) ||
                TileIsWall(map_ptr, x - 1, y + 1)
            );
        case J_RIGHT:
            return !(
                TileIsWall(map_ptr, x + 2, y) ||
                TileIsWall(map_ptr, x + 2, y + 1)
            );
        case J_UP:
            return !(
                TileIsWall(map_ptr, x + 0, y - 1) ||
                TileIsWall(map_ptr, x + 1, y - 1)
            );
        case J_DOWN:
            return !(
                TileIsWall(map_ptr, x + 0, y + 2) ||
                TileIsWall(map_ptr, x + 1, y + 2)
            );
        default:
            droplet_ptr->pressed = 0;
            return 0;
    }
}
