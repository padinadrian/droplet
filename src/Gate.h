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
} Gate;

#endif  /* DROPLET_GATE_H */
