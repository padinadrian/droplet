/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/05/08
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Gate.h"
#include "SpriteTileIndex.h"

/* ===== Functions ===== */

/** Set the gate state and display the animation. */
void SetGateState(Gate* gate_ptr, GateState state)
{
    UINT8 sprite_tile;
    if (GATE_CLOSED == state) {
        sprite_tile = SPRITE_GATE;
    }
    else {
        sprite_tile = SPRITE_NULL;
    }
    set_sprite_tile(gate_ptr->sprite, sprite_tile);
    gate_ptr->state = state;
}

/** Change the gate state to the opposite of the current state. */
void FlipGate(Gate* gate_ptr)
{
    if (GATE_CLOSED == gate_ptr->state) {
        SetGateState(gate_ptr, GATE_OPEN);
    }
    else {
        SetGateState(gate_ptr, GATE_CLOSED);
    }
}