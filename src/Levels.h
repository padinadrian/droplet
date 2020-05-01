/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/26
 */

#ifndef DROPLET_LEVELS_H
#define DROPLET_LEVELS_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Level.h"

/* ===== Functions ===== */

/** Initialize all levels. */
void InitializeLevels();

/**
 * Main game loop which runs the given level.
 */
void PlayLevel(UINT8 level_number);

#endif  /* DROPLET_LEVELS_H */
