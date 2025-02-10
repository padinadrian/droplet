/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-05-23
 */

/* ===== Includes ===== */
#include "objects/Gate.h"
#include "objects/Droplet.h"
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
void InitializeLevel2(Level* level_ptr)
{
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
    level_ptr->num_switches = LEVEL2_NUM_SWITCHES;
    level_ptr->num_gates = LEVEL2_NUM_GATES;

    level_ptr->switches[0].pos.x = (6 << 3) + 4;
    level_ptr->switches[0].pos.y = (4 << 3);
    level_ptr->switches[0].state = SWITCH_OFF;
    level_ptr->switches[0].direction = SPRITE_DIR_DOWN;

    level_ptr->switches[1].pos.x = (12 << 3) + 4;
    level_ptr->switches[1].pos.y = (4 << 3);
    level_ptr->switches[1].state = SWITCH_OFF;
    level_ptr->switches[1].direction = SPRITE_DIR_DOWN;

    level_ptr->switches[2].pos.x = (6 << 3) + 4;
    level_ptr->switches[2].pos.y = (13 << 3);
    level_ptr->switches[2].state = SWITCH_OFF;
    level_ptr->switches[2].direction = SPRITE_DIR_UP;

    level_ptr->switches[3].pos.x = (12 << 3) + 4;
    level_ptr->switches[3].pos.y = (13 << 3);
    level_ptr->switches[3].state = SWITCH_OFF;
    level_ptr->switches[3].direction = SPRITE_DIR_UP;

    /* Gates */
    level_ptr->gates[0].pos.x = (14 << 3);
    level_ptr->gates[0].pos.y = (8 << 3);
    level_ptr->gates[0].num_switches = 0;
    level_ptr->gates[0].state = GATE_CLOSED;

    level_ptr->gates[1].pos.x = (14 << 3);
    level_ptr->gates[1].pos.y = (9 << 3);
    level_ptr->gates[1].num_switches = 0;
    level_ptr->gates[1].state = GATE_CLOSED;

    level_ptr->gates[2].pos.x = (15 << 3);
    level_ptr->gates[2].pos.y = (8 << 3);
    level_ptr->gates[2].num_switches = 0;
    level_ptr->gates[2].state = GATE_CLOSED;

    level_ptr->gates[3].pos.x = (15 << 3);
    level_ptr->gates[3].pos.y = (9 << 3);
    level_ptr->gates[3].num_switches = 0;
    level_ptr->gates[3].state = GATE_CLOSED;

    level_ptr->gates[4].pos.x = (16 << 3);
    level_ptr->gates[4].pos.y = (8 << 3);
    level_ptr->gates[4].num_switches = 0;
    level_ptr->gates[4].state = GATE_CLOSED;

    level_ptr->gates[5].pos.x = (16 << 3);
    level_ptr->gates[5].pos.y = (9 << 3);
    level_ptr->gates[5].num_switches = 0;
    level_ptr->gates[5].state = GATE_CLOSED;

    /* Gate Switches */
    level_ptr->gateswitches[0].switch_index = 0;
    level_ptr->gateswitches[0].trigger_state = SWITCH_ON;
    level_ptr->gateswitches[1].switch_index = 1;
    level_ptr->gateswitches[1].trigger_state = SWITCH_OFF;
    level_ptr->gateswitches[2].switch_index = 2;
    level_ptr->gateswitches[2].trigger_state = SWITCH_OFF;
    level_ptr->gateswitches[3].switch_index = 3;
    level_ptr->gateswitches[3].trigger_state = SWITCH_ON;

    level_ptr->gates[0].switches = &level_ptr->gateswitches[0];
    level_ptr->gates[0].num_switches = 2;
    level_ptr->gates[1].switches = &level_ptr->gateswitches[0];
    level_ptr->gates[1].num_switches = 2;

    level_ptr->gates[2].switches = &level_ptr->gateswitches[2];
    level_ptr->gates[2].num_switches = 2;
    level_ptr->gates[3].switches = &level_ptr->gateswitches[2];
    level_ptr->gates[3].num_switches = 2;

    level_ptr->gates[4].switches = &level_ptr->gateswitches[0];
    level_ptr->gates[4].num_switches = 4;
    level_ptr->gates[5].switches = &level_ptr->gateswitches[0];
    level_ptr->gates[5].num_switches = 4;
}