/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-05-24
 */

#ifndef DROPLET_LEVEL_SELECTOR_H
#define DROPLET_LEVEL_SELECTOR_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Position.h"

/* ===== Data Types ===== */

/** Tracks position and sprite info for selector. */
typedef struct {
    UINT8 sprites[6];
    Position pos;
} LevelSelector;

/* ===== Functions ===== */

/** Display the selector at the starting position. */
void InitializeSelector(LevelSelector* selector_ptr);

/**
 * Move the selector in the given direction.
 * If the movement is invalid (end of row/column)
 * this does nothing.
 */
void MoveSelector(LevelSelector* selector_ptr, UINT8 direction);

/**
 * Return the level number of the currently highlighted level.
 */
UINT8 SelectLevel(LevelSelector* selector_ptr);

#endif  /* DROPLET_LEVEL_SELECTOR_H */