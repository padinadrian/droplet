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
UINT8 TileIsWall(BackgroundMap* map_ptr, UINT8 x, UINT8 y)
{
    int index = (map_ptr->width * (int)y) + x;
    return (
        (map_ptr->map_data[index] != BG_TILE_STAIRCASE_TL) &&
        (map_ptr->map_data[index] != BG_TILE_STAIRCASE_BL) &&
        (map_ptr->map_data[index] != BG_TILE_STAIRCASE_TR) &&
        (map_ptr->map_data[index] != BG_TILE_STAIRCASE_BR) &&
        (map_ptr->map_data[index] != BG_TILE_NULL)
    );
}
