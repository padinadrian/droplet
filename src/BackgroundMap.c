/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

/* ===== Includes ===== */
#include "BackgroundMap.h"
#include "BackgroundTileIndex.h"

/* ===== Functions ===== */

/** Set the background. */
void SetBackground(BackgroundMap* map_ptr)
{
    set_bkg_tiles(
        0,
        0,
        map_ptr->width,
        map_ptr->height,
        map_ptr->map_data
    );
}

/** Return 1 if the tile is a wall, 0 otherwise. */
UINT8 TileIsWall(BackgroundMap* map_ptr, Position* pos_ptr)
{
    UINT8 x = pos_ptr->x;
    UINT8 y = pos_ptr->y;
    UINT16 index = (map_ptr->width * (UINT16)y) + x;
    return (
        (map_ptr->map_data[index] != BG_TILE_STAIRCASE_TL) &&
        (map_ptr->map_data[index] != BG_TILE_STAIRCASE_BL) &&
        (map_ptr->map_data[index] != BG_TILE_STAIRCASE_TR) &&
        (map_ptr->map_data[index] != BG_TILE_STAIRCASE_BR) &&
        (map_ptr->map_data[index] != BG_TILE_NULL)
    );
}
