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

/* Object counters */
static enum { LEVEL3_NUM_SWITCHES = 0 };
static enum { LEVEL3_NUM_GATES = 0 };
static enum {
    LEVEL3_SPIDER_0,
    LEVEL3_NUM_SPIDERS,
};

/**
 * TODO: Move this to a proper data file instead of living
 * in a source file.
 */
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

    /* Gates and switches */
    level_ptr->num_switches = LEVEL3_NUM_SWITCHES;
    level_ptr->num_gates = LEVEL3_NUM_GATES;

    /* Enemies */
    level_ptr->num_spiders = LEVEL3_NUM_SPIDERS;
    level_ptr->spiders[LEVEL3_SPIDER_0].pos.x = 14;
    level_ptr->spiders[LEVEL3_SPIDER_0].pos.y = 2;

    level_ptr->spiders[LEVEL3_SPIDER_0].num_walls = 1;
    level_ptr->spiders[LEVEL3_SPIDER_0].walls[0].x = 7;
    level_ptr->spiders[LEVEL3_SPIDER_0].walls[0].y = 2;
}
