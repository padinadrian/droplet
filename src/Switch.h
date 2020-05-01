/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/25
 */

#ifndef DROPLET_SWITCH_H
#define DROPLET_SWITCH_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Position.h"

/* ===== Data Types ===== */

typedef enum {
    SWITCH_ON,
    SWITCH_OFF
} SwitchState;

typedef struct {
    Position pos;
    SwitchState state;
} Switch;

#endif  /* DROPLET_SWITCH_H */
