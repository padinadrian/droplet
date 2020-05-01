/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

/* ===== Includes ===== */
#include "Position.h"

/* ===== Functions ===== */

/** Copy a Position object from dest into src. */
void PositionCopy(Position* dest, const Position* src)
{
    dest->x = src->x;
    dest->y = src->y;
}

/** Compare two Positions to see if they are the same. */
UINT8 PositionCompare(const Position* pos1, const Position* pos2)
{
    return ((pos1->x == pos2->x) && (pos1->y == pos2->y));
}

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
    grid_pos_ptr->x += 8;
    grid_pos_ptr->y += 16;
}
