/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-15
 */

/* ===== Includes ===== */
#include "Level.h"
#include "Position.h"
#include "objects/Droplet.h"

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
        Position droplet_pos)
{
    return PositionCompare(
        droplet_pos,
        level_ptr->exit_pos
    );
}

/**
 * Helper function - check edge detection before moving sprite.
 */
int DropletCheckMovement(
        Level* level_ptr,
        UINT8 joypad_input)
{
    Position next_pos1;
    Position next_pos2;
    Position next_px_pos1;
    Position next_px_pos2;
    BackgroundMap* map_ptr;

    map_ptr = &(level_ptr->level_map);

    PositionCopy(&next_pos1, droplet_global.pos);
    PositionCopy(&next_pos2, droplet_global.pos);

    /* Determine which tiles Droplet is trying to move into. */
    switch (joypad_input)
    {
        case J_LEFT:
            next_pos1.x -= 1;
            next_pos2.x -= 1;
            next_pos2.y += 1;
            break;
        case J_RIGHT:
            next_pos1.x += 2;
            next_pos2.x += 2;
            next_pos2.y += 1;
            break;
        case J_UP:
            next_pos1.y -= 1;
            next_pos2.x += 1;
            next_pos2.y -= 1;
            break;
        case J_DOWN:
            next_pos1.y += 2;
            next_pos2.x += 1;
            next_pos2.y += 2;
            break;
        default:
            /* TODO: This should be unreachable. */
            droplet_global.pressed = 0;
            return 0;
    }

    PositionCopy(&next_px_pos1, next_pos1);
    PositionCopy(&next_px_pos2, next_pos2);
    GridPosToPixelPos(&next_px_pos1);
    GridPosToPixelPos(&next_px_pos2);

    return !(
        TileIsWall(map_ptr, &next_pos1) ||
        TileIsWall(map_ptr, &next_pos2) ||
        PosIsClosedGate(level_ptr->gates, level_ptr->num_gates, next_px_pos1) ||
        PosIsClosedGate(level_ptr->gates, level_ptr->num_gates, next_px_pos2)
    );
}
