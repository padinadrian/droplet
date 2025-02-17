/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-05-08
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Switch.h"
#include "SpriteTileIndex.h"

/* ===== Functions ===== */

/** Set the switch state and display the animation. */
void SetSwitchState(Switch* switch_ptr, SwitchState state)
{
    set_sprite_tile(
        switch_ptr->sprite,
        SPRITE_SWITCH_DOWN_OFF + switch_ptr->direction + state
    );
    switch_ptr->state = state;
}

/** Change the switch state to the opposite of the current state. */
void FlipSwitch(Switch* switch_ptr)
{
    if (SWITCH_ON == switch_ptr->state) {
        SetSwitchState(switch_ptr, SWITCH_OFF);
    }
    else {
        SetSwitchState(switch_ptr, SWITCH_ON);
    }
}

/** Flip any nearby switches. */
void FlipNearbySwitches(
        Switch* switches,
        UINT8 num_switches,
        Position droplet_pos)
{
    Position* switch_pos;
    Position droplet_pos_copy;
    UINT8 i;

    PositionCopy(&droplet_pos_copy, droplet_pos);
    GridPosToPixelPos(&droplet_pos_copy);

    /* Measure from the (approximate) middle of the sprite. */
    droplet_pos_copy.x += 8;
    droplet_pos_copy.y += 8;

    /* TODO: Flip any switches within 8 pixels. */
    for (i = 0; i < num_switches; ++i) {
        switch_pos = &(switches[i].pos);
        if (PositionProximityCheck(switch_pos, &droplet_pos_copy)) {
            FlipSwitch(&switches[i]);
        }
    }
}
