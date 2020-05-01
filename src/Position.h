/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

#ifndef DROPLET_POSITION_H
#define DROPLET_POSITION_H

/* ===== Includes ===== */
#include <gb/gb.h>

/* ===== Data Types ===== */

typedef struct {
    UINT8 x;
    UINT8 y;
} Position;

/* ===== Functions ===== */

/**
 * Copy a Position object from dest into src.
 */
void PositionCopy(Position* dest, const Position* src);

/**
 * Compare two Positions to see if they are the same.
 * Returns 1 if Positions are the same, 0 otherwise.
 * TODO: Should this be inlined?
 */
UINT8 PositionCompare(const Position* pos1, const Position* pos2);

/**
 * Convert a position in the grid coordinate system to a
 * position in the pixel coordinate system.
 * Operation is performed inline on the object itself.
 */
void GridPosToPixelPos(Position* grid_pos_ptr);


#endif  /* DROPLET_POSITION_H */
