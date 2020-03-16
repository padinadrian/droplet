/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

/* ===== Includes ===== */
#include "Position.h"

/* ===== Functions ===== */

/**
 * Convert a position in the grid coordinate system to a
 * position in the pixel coordinate system.
 * Operation is performed inline on the object itself.
 */
void GridPosToPixelPos(Position* grid_pos)
{
    /* TODO: Take scrolling into consideration */
    grid_pos->x <<= 3;
    grid_pos->y <<= 3;
}
