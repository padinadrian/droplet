/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/05/21
 */

#ifndef DROPLET_TEST_UTILS_H
#define DROPLET_TEST_UTILS_H

/* ===== Includes ===== */
#include <stdio.h>
#include "Switch.h"
#include "Gate.h"
#include "Level.h"

/* ===== Pretty Printing ===== */

static inline void PrintPosition(
    const char* label,
    const Position* pos_ptr
)
{
    printf(
        "pos: %s; x: %d, y: %d\n",
        label,
        pos_ptr->x,
        pos_ptr->y
    );
}

static inline void PrintSwitch(
    const char* label,
    const Switch* switch_ptr
)
{
    printf("switch: %s\n", label);
    PrintPosition("sw", &switch_ptr->pos);
    printf(
        "state: %d; sprite: %d\n",
        (int)switch_ptr->state,
        (int)switch_ptr->sprite
    );
}

static inline void PrintGateSwitch(
    const char* label,
    const GateSwitch* gatesw_ptr
)
{
    printf("gate-sw: %s\n", label);
    printf(
        "switch id: %d; trigger: %d\n",
        (int)gatesw_ptr->switch_index,
        (int)gatesw_ptr->trigger_state
    );
}

static inline void PrintGate(
    const char* label,
    const Gate* gate_ptr
)
{
    printf("gate: %s\n", label);
    PrintPosition("g", &gate_ptr->pos);
    printf(
        "state: %d; sprite: %d\n",
        (int)gate_ptr->state,
        (int)gate_ptr->sprite
    );
    printf("gate switches: %d\n", gate_ptr->num_switches);
    for (int i = 0; i < gate_ptr->num_switches; ++i)
    {
        PrintGateSwitch("gs", gate_ptr->switches + i);
    }
}

static inline void PrintLevel(
    const char* label,
    const Level* level_ptr
)
{
    printf("level: %s\n", label);
}

#endif  /* DROPLET_TEST_UTILS_H */