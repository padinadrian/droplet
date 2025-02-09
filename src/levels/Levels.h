/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/26
 */

#ifndef DROPLET_LEVELS_H
#define DROPLET_LEVELS_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Level.h"

/* ===== Data Types ===== */
typedef void (*LevelFunction)(Level*);

// List of levels
enum {
    LEVEL1,
    LEVEL2,
    NUM_LEVELS,
};

// TODO: ROM Bank map

/* ===== Functions ===== */

/**
 * Main game loop which runs the given level.
 */
void PlayLevel(UINT8 level_number);

/* ===== LEVELS ===== */
void InitializeLevel1(Level* level_ptr);
void InitializeLevel2(Level* level_ptr);


#endif  /* DROPLET_LEVELS_H */
