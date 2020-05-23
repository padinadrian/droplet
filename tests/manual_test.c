/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/05/21
 */

/* ===== Includes ===== */
#include "test_utils.h"

int main()
{
    Switch s = {
        .pos = {.x = 5, .y = 10},
        .state = SWITCH_ON,
        .sprite = 39,
    };

    GateSwitch gs = {
        .switch_index = 0,
        .trigger_state = SWITCH_OFF
    };

    Gate g = {
        .pos = {.x = 3, .y = 4},
        .state = GATE_OPEN,
        .switches = &gs,
        .num_switches = 1,
        .sprite = 27,
    };

    PrintSwitch("sw1", &s);
    PrintGateSwitch("gs1", &gs);
    PrintGate("g1", &g);
}