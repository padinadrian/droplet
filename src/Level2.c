/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/05/23
 */

/* ===== Includes ===== */
#include "Gate.h"
#include "Droplet.h"
#include "Position.h"
#include "Level.h"
#include "SpriteTileIndex.h"
#include "data/maps/droplet_level2_bg.h"

/* ===== Functions ===== */

/**
 * TODO: Move this to a proper data file instead of living
 * in a source file.
 */
static enum { LEVEL2_NUM_SWITCHES = 4 };
static enum { LEVEL2_NUM_GATES = 6 };
static enum { LEVEL2_NUM_GATE_SW = 4 };
void InitializeLevel2(Level* level_ptr)
{
    /* Static Data */
    static Switch switches[LEVEL2_NUM_SWITCHES];
    static Gate gates[LEVEL2_NUM_GATES];
    static GateSwitch gate_sw[LEVEL2_NUM_GATE_SW];

    /* Background */
    SetLevelBackground(
        level_ptr,
        DropletBackgroundLevel2,
        DropletBackgroundLevel2Width,
        DropletBackgroundLevel2Height
    );

    /* Start and End Positions */
    level_ptr->start_pos.x = 1;
    level_ptr->start_pos.y = 8;
    level_ptr->exit_pos.x = 17;
    level_ptr->exit_pos.y = 8;

    /* Switches */
    level_ptr->switches = switches;
    level_ptr->num_switches = LEVEL2_NUM_SWITCHES;
    level_ptr->gates = gates;
    level_ptr->num_gates = LEVEL2_NUM_GATES;

    switches[0].pos.x = (6 << 3) + 4;
    switches[0].pos.y = (4 << 3);
    switches[0].state = SWITCH_OFF;
    switches[0].direction = SPRITE_DIR_DOWN;

    switches[1].pos.x = (12 << 3) + 4;
    switches[1].pos.y = (4 << 3);
    switches[1].state = SWITCH_OFF;
    switches[1].direction = SPRITE_DIR_DOWN;

    switches[2].pos.x = (6 << 3) + 4;
    switches[2].pos.y = (13 << 3);
    switches[2].state = SWITCH_OFF;
    switches[2].direction = SPRITE_DIR_UP;

    switches[3].pos.x = (12 << 3) + 4;
    switches[3].pos.y = (13 << 3);
    switches[3].state = SWITCH_OFF;
    switches[3].direction = SPRITE_DIR_UP;

    /* Gates */
    gates[0].pos.x = (14 << 3);
    gates[0].pos.y = (8 << 3);
    gates[0].num_switches = 0;
    gates[0].state = GATE_CLOSED;

    gates[1].pos.x = (14 << 3);
    gates[1].pos.y = (9 << 3);
    gates[1].num_switches = 0;
    gates[1].state = GATE_CLOSED;

    gates[2].pos.x = (15 << 3);
    gates[2].pos.y = (8 << 3);
    gates[2].num_switches = 0;
    gates[2].state = GATE_CLOSED;

    gates[3].pos.x = (15 << 3);
    gates[3].pos.y = (9 << 3);
    gates[3].num_switches = 0;
    gates[3].state = GATE_CLOSED;

    gates[4].pos.x = (16 << 3);
    gates[4].pos.y = (8 << 3);
    gates[4].num_switches = 0;
    gates[4].state = GATE_CLOSED;

    gates[5].pos.x = (16 << 3);
    gates[5].pos.y = (9 << 3);
    gates[5].num_switches = 0;
    gates[5].state = GATE_CLOSED;

    /* Gate Switches */
    gate_sw[0].switch_index = 0;
    gate_sw[0].trigger_state = SWITCH_ON;
    gate_sw[1].switch_index = 1;
    gate_sw[1].trigger_state = SWITCH_OFF;
    gate_sw[2].switch_index = 2;
    gate_sw[2].trigger_state = SWITCH_OFF;
    gate_sw[3].switch_index = 3;
    gate_sw[3].trigger_state = SWITCH_ON;

    gates[0].switches = &gate_sw[0];
    gates[0].num_switches = 2;
    gates[1].switches = &gate_sw[0];
    gates[1].num_switches = 2;

    gates[2].switches = &gate_sw[2];
    gates[2].num_switches = 2;
    gates[3].switches = &gate_sw[2];
    gates[3].num_switches = 2;

    gates[4].switches = &gate_sw[0];
    gates[4].num_switches = 4;
    gates[5].switches = &gate_sw[0];
    gates[5].num_switches = 4;
}