/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

/* ===== Includes ===== */
#include "DropletMap.h"

/* ===== Functions ===== */

/** Return 1 if the tile is a wall, 0 otherwise. */
UINT8 TileIsWall(DropletMap* map_ptr, UINT8 x, UINT8 y)
{
    int index = (map_ptr->width * (int)y) + x;
    return map_ptr->map_data[index] != 0;
}
