/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/30
 */

#ifndef DROPLET_GATE_H
#define DROPLET_GATE_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Position.h"
#include "Switch.h"

/* ===== Data Types ===== */

/** Defines the state of the gate. */
typedef enum {
    GATE_OPEN,
    GATE_CLOSED
} GateState;

/** Switches that the gate triggers on. */
typedef struct {
    UINT8 switch_index;
    SwitchState trigger_state;
} GateSwitch;

/** The gate sprite and state information. */
typedef struct {
    Position pos;
    GateState state;
    GateSwitch* switches;
    UINT8 num_switches;
    UINT8 sprite;
} Gate;

/* ===== Functions ===== */

/** Set the gate state and display the animation. */
void SetGateState(Gate* gate_ptr, GateState state);

/** Change the gate state to the opposite of the current state. */
void FlipGate(Gate* gate_ptr);

/** Activate any gates triggered by switches. */
void CheckGateSwitches(Gate* gates, UINT8 num_gates, Switch* switches);

/** Check if the given position is a closed gate. */
UINT8 PosIsClosedGate(Gate* gates, UINT8 num_gates, Position* pos_ptr);

#endif  /* DROPLET_GATE_H */
