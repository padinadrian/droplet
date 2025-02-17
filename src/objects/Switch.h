/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-04-25
 */

#ifndef DROPLET_SWITCH_H
#define DROPLET_SWITCH_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Position.h"
#include "SpriteTileIndex.h"

/* ===== Data Types ===== */

typedef enum {
    SWITCH_OFF = 0,
    SWITCH_ON  = 4
} SwitchState;

typedef struct {
    Position pos;
    SwitchState state;
    SpriteDirection direction;
    UINT8 sprite;
} Switch;

/* ===== Functions ===== */

/** Set the switch state and display the animation. */
void SetSwitchState(Switch* switch_ptr, SwitchState state);

/** Change the switch state to the opposite of the current state. */
void FlipSwitch(Switch* switch_ptr);

/**
 * Search through the list of switches and flip any that
 * are close to the given position.
 */
void FlipNearbySwitches(
    Switch* switches,
    UINT8 num_switches,
    Position droplet_pos
);

#endif  /* DROPLET_SWITCH_H */
