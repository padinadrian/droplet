/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/25
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Level.h"
#include "Gate.h"
#include "Switch.h"
#include "Droplet.h"
#include "data/maps/droplet_level1_bg.h"

/* ===== LEVELS ===== */

/** LEVEL 1 **/
/**
 * TODO: Move this to a proper data file instead of living
 * in a source file.
 */
static enum { LEVEL1_NUM_GATES = 6 };
static enum { LEVEL1_NUM_SWITCHES = 3 };
void InitializeLevel1(Level* level_ptr)
{
    /* Gates and Switches */
    /*
    const Gate gates[LEVEL1_NUM_GATES];
    const Switch switches[LEVEL1_NUM_SWITCHES];
    const GateSwitch gate_switches[LEVEL1_NUM_GATE_SWITCHES];
    */

    SetLevelBackground(
        level_ptr,
        DropletBackgroundLevel1,
        DropletBackgroundLevel1Width,
        DropletBackgroundLevel1Height
    );

    /* Start and Exit Positions */
    level_ptr->droplet_start_pos.x = 1;
    level_ptr->droplet_start_pos.y = 10;
    level_ptr->exit_pos.x = 17;
    level_ptr->exit_pos.y = 10;

    /* Switches */
    level_ptr->num_switches = LEVEL1_NUM_SWITCHES;

    level_ptr->switches[0].state = SWITCH_OFF;
    level_ptr->switches[0].pos.x = (5 << 3) + 4;
    level_ptr->switches[0].pos.y = (5 << 3);

    level_ptr->switches[1].state = SWITCH_OFF;
    level_ptr->switches[1].pos.x = (9 << 3) + 4;
    level_ptr->switches[1].pos.y = (5 << 3);

    level_ptr->switches[2].state = SWITCH_OFF;
    level_ptr->switches[2].pos.x = (13 << 3) + 4;
    level_ptr->switches[2].pos.y = (5 << 3);

    /* Gates */
    level_ptr->num_gates = LEVEL1_NUM_GATES;

    level_ptr->gates[0].state = GATE_CLOSED;
    level_ptr->gates[0].pos.x = (9 << 3);
    level_ptr->gates[0].pos.y = (9 << 3);

    level_ptr->gates[1].state = GATE_CLOSED;
    level_ptr->gates[1].pos.x = (10 << 3);
    level_ptr->gates[1].pos.y = (9 << 3);

    level_ptr->gates[2].state = GATE_CLOSED;
    level_ptr->gates[2].pos.x = (13 << 3);
    level_ptr->gates[2].pos.y = (9 << 3);

    level_ptr->gates[3].state = GATE_CLOSED;
    level_ptr->gates[3].pos.x = (14 << 3);
    level_ptr->gates[3].pos.y = (9 << 3);

    level_ptr->gates[4].state = GATE_CLOSED;
    level_ptr->gates[4].pos.x = (15 << 3);
    level_ptr->gates[4].pos.y = (10 << 3);

    level_ptr->gates[5].state = GATE_CLOSED;
    level_ptr->gates[5].pos.x = (15 << 3);
    level_ptr->gates[5].pos.y = (11 << 3);

    /* Gate Switches */
    level_ptr->gates[0].num_switches = 1;
    level_ptr->gates[0].switches[0].switch_index = 0;
    level_ptr->gates[0].switches[0].trigger_state = SWITCH_ON;

    level_ptr->gates[1].num_switches = 1;
    level_ptr->gates[1].switches[0].switch_index = 0;
    level_ptr->gates[1].switches[0].trigger_state = SWITCH_ON;

    level_ptr->gates[2].num_switches = 1;
    level_ptr->gates[2].switches[0].switch_index = 1;
    level_ptr->gates[2].switches[0].trigger_state = SWITCH_ON;

    level_ptr->gates[3].num_switches = 1;
    level_ptr->gates[3].switches[0].switch_index = 1;
    level_ptr->gates[3].switches[0].trigger_state = SWITCH_ON;

    level_ptr->gates[4].num_switches = 1;
    level_ptr->gates[4].switches[0].switch_index = 2;
    level_ptr->gates[4].switches[0].trigger_state = SWITCH_ON;

    level_ptr->gates[4].num_switches = 1;
    level_ptr->gates[4].switches[0].switch_index = 2;
    level_ptr->gates[4].switches[0].trigger_state = SWITCH_ON;
}
