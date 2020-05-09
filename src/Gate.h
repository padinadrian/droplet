/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/30
 */

#ifndef DROPLET_GATE_H
#define DROPLET_GATE_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Position.h"

/* ===== Data Types ===== */

typedef enum {
    GATE_OPEN,
    GATE_CLOSED
} GateState;

typedef struct {
    Position pos;
    GateState state;
    UINT8 sprite;
} Gate;

/* ===== Functions ===== */

/** Set the gate state and display the animation. */
void SetGateState(Gate* gate_ptr, GateState state);

/** Change the gate state to the opposite of the current state. */
void FlipGate(Gate* gate_ptr);

#endif  /* DROPLET_GATE_H */
