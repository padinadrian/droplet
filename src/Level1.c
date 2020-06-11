/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/05/23
 */

/* ===== Includes ===== */
#include "Gate.h"
#include "Droplet.h"
#include "Position.h"
#include "Level.h"
#include "data/maps/droplet_level1_bg.h"

/* ===== Functions ===== */

/**
 * TODO: Move this to a proper data file instead of living
 * in a source file.
 */
static enum { LEVEL1_NUM_SWITCHES = 3 };
static enum { LEVEL1_NUM_GATES = 6 };
void InitializeLevel1(Level* level_ptr)
{
    const Switch* switches = &level_ptr->switches;
    const Gate* gates = &level_ptr->gates;
    const GateSwitch* gateswitches = &level_ptr->gateswitches;

    /* Background */
    SetLevelBackground(
        level_ptr,
        DropletBackgroundLevel1,
        DropletBackgroundLevel1Width,
        DropletBackgroundLevel1Height
    );

    /* Start and End Positions */
    level_ptr->start_pos.x = 1;
    level_ptr->start_pos.y = 10;
    level_ptr->exit_pos.x = 17;
    level_ptr->exit_pos.y = 10;

    /* Switches */
    switches[0].state = SWITCH_OFF;
    switches[0].direction = SPRITE_DIR_DOWN;
    switches[0].pos.x = (5 << 3) + 4;
    switches[0].pos.y = (5 << 3);

    switches[1].state = SWITCH_OFF;
    switches[1].direction = SPRITE_DIR_DOWN;
    switches[1].pos.x = (9 << 3) + 4;
    switches[1].pos.y = (5 << 3);

    switches[2].state = SWITCH_OFF;
    switches[2].direction = SPRITE_DIR_DOWN;
    switches[2].pos.x = (13 << 3) + 4;
    switches[2].pos.y = (5 << 3);

    /* Gates */
    gates[0].state = GATE_CLOSED;
    gates[0].pos.x = (9 << 3);
    gates[0].pos.y = (9 << 3);

    gates[1].state = GATE_CLOSED;
    gates[1].pos.x = (10 << 3);
    gates[1].pos.y = (9 << 3);

    gates[2].state = GATE_CLOSED;
    gates[2].pos.x = (13 << 3);
    gates[2].pos.y = (9 << 3);

    gates[3].state = GATE_CLOSED;
    gates[3].pos.x = (14 << 3);
    gates[3].pos.y = (9 << 3);

    gates[4].state = GATE_CLOSED;
    gates[4].pos.x = (15 << 3);
    gates[4].pos.y = (10 << 3);

    gates[5].state = GATE_CLOSED;
    gates[5].pos.x = (15 << 3);
    gates[5].pos.y = (11 << 3);

    /* Gate Switches */
    gateswitches[0].switch_index = 0;
    gateswitches[0].trigger_state = SWITCH_ON;
    gateswitches[1].switch_index = 1;
    gateswitches[1].trigger_state = SWITCH_ON;
    gateswitches[2].switch_index = 2;
    gateswitches[2].trigger_state = SWITCH_ON;

    gates[0].switches = &gateswitches[0];
    gates[0].num_switches = 1;
    gates[1].switches = &gateswitches[0];
    gates[1].num_switches = 1;

    gates[2].switches = &gateswitches[1];
    gates[2].num_switches = 1;
    gates[3].switches = &gateswitches[1];
    gates[3].num_switches = 1;

    gates[4].switches = &gateswitches[2];
    gates[4].num_switches = 1;
    gates[5].switches = &gateswitches[2];
    gates[5].num_switches = 1;

    level_ptr->num_switches = LEVEL1_NUM_SWITCHES;
    level_ptr->num_gates = LEVEL1_NUM_GATES;
}