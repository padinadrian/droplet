/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2024-02-09
 */

/* ===== Includes ===== */
#include "objects/Droplet.h"
#include "Position.h"
#include "Level.h"
#include "SpriteTileIndex.h"
#include "data/maps/droplet_level3_bg.h"

/* ===== Functions ===== */

/**
 * TODO: Move this to a proper data file instead of living
 * in a source file.
 */
static enum { LEVEL3_NUM_SWITCHES = 0 };
static enum { LEVEL3_NUM_GATES = 0 };
void InitializeLevel3(Level* level_ptr)
{
    /* Background */
    SetLevelBackground(
        level_ptr,
        DropletBackgroundLevel3,
        DropletBackgroundLevel3Width,
        DropletBackgroundLevel3Height
    );

    /* Start and End Positions */
    level_ptr->start_pos.x = 2;
    level_ptr->start_pos.y = 2;
    level_ptr->exit_pos.x = 17;
    level_ptr->exit_pos.y = 14;

    /* Switches */
    level_ptr->num_switches = LEVEL3_NUM_SWITCHES;
    level_ptr->num_gates = LEVEL3_NUM_GATES;
}