/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-05-08
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Gate.h"
#include "SpriteTileIndex.h"

/* ===== Functions ===== */

/** Initialize Gate object. */
void InitializGate(Gate* gate_ptr)
{
    gate_ptr->sprite = NewSpriteID();
    MoveSprite(
        gate_ptr->sprite,
        gate_ptr->pos.x,
        gate_ptr->pos.y
    );
    SetGateState(
        gate_ptr,
        gate_ptr->state
    );
}

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

/** Activate any gates triggered by switches. */
void CheckGateSwitches(
    Gate* gates,
    UINT8 num_gates,
    Switch* switches)
{
    UINT8 gid;
    UINT8 sid;
    UINT8 gsid;
    UINT8 triggered;
    UINT8 num_gate_switches;
    SwitchState trigger_state;
    SwitchState switch_state;

    /** Loop over gates. */
    for (gid = 0; gid < num_gates; ++gid) {

        /** Loop over gate switches for this gate. */
        num_gate_switches = gates[gid].num_switches;
        if (num_gate_switches > 0) {
            triggered = 1;
            for (gsid = 0; gsid < num_gate_switches; ++gsid) {
                sid = gates[gid].switches[gsid].switch_index;
                switch_state = switches[sid].state;
                trigger_state = gates[gid].switches[gsid].trigger_state;
                if (switch_state != trigger_state) {
                    triggered = 0;
                    break;
                }
            }
        }
        else {
            triggered = 0;
        }

        if (triggered && (GATE_CLOSED == gates[gid].state)) {
            SetGateState(&gates[gid], GATE_OPEN);
        }
        else if (!triggered && (GATE_OPEN == gates[gid].state)) {
            SetGateState(&gates[gid], GATE_CLOSED);
        }
    }
}

/** Check if the given position is a closed gate. */
UINT8 PosIsClosedGate(Gate* gates, UINT8 num_gates, Position* pos_ptr)
{
    UINT8 i;
    UINT8 found = 0;
    UINT8 comp = 0;
    for (i = 0; i < num_gates; ++i) {
        comp = PositionCompare(&(gates[i].pos), pos_ptr);
        if (comp && (GATE_CLOSED == gates[i].state)) {
            found = 1;
            break;
        }
    }
    return found;
}
