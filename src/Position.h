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
 * Convert a position in the grid coordinate system to a
 * position in the pixel coordinate system.
 * Operation is performed inline on the object itself.
 */
void GridPosToPixelPos(Position* grid_pos);


#endif  /* DROPLET_POSITION_H */
