/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-15
 */

#ifndef DROPLET_LEVEL_H
#define DROPLET_LEVEL_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "objects/Droplet.h"
#include "objects/Gate.h"
#include "objects/Spider.h"
#include "objects/Switch.h"
#include "Position.h"
#include "BackgroundMap.h"

/* ===== Data Types ===== */

// Data needed to manage the level.
typedef struct {
    BackgroundMap level_map;
    Position start_pos;
    Position exit_pos;
    Switch switches[10];
    UINT8 num_switches;
    Gate gates[10];
    UINT8 num_gates;
    Spider spiders[10];
    UINT8 num_spiders;
    // TODO: Are we using GateSwitches?
    GateSwitch gateswitches[10];
} Level;

/* ===== Functions ===== */

/** Reset the level. */
static inline void ResetLevel(Level* level_ptr)
{
    level_ptr->num_switches = 0;
    level_ptr->num_gates = 0;
    level_ptr->num_spiders = 0;
}

/**
 * Assigns the level map data to the level.
 */
void SetLevelBackground(
    Level* level_ptr,
    UINT8* map_data,
    UINT8 map_width,
    UINT8 map_height
);

/**
 * Checks if Droplet has reached the end of the level.
 * Return 1 if the level is complete, otherwise 0.
 */
UINT8 IsLevelComplete(
    Level* level_ptr,
    Position* droplet_pos_ptr
);

/**
 * Helper function - check edge detection before moving sprite.
 */
int DropletCheckMovement(
    Level* level_ptr,
    UINT8 joypad_input
);

#endif  /* DROPLET_LEVEL_H */
