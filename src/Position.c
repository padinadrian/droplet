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
void GridPosToPixelPos(Position* grid_pos_ptr)
{
    /* TODO: Take scrolling into consideration */
    grid_pos_ptr->x <<= 3;
    grid_pos_ptr->y <<= 3;
}
