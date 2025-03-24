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
enum { LEVEL3_NUM_SWITCHES = 0 };
enum { LEVEL3_NUM_GATES = 0 };
enum {
    LEVEL3_SPIDER_0,
    LEVEL3_SPIDER_1,
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
    level_ptr->spiders[LEVEL3_SPIDER_0].state.direction = DIRECTION_LEFT;

    level_ptr->spiders[LEVEL3_SPIDER_0].num_walls = 4;
    level_ptr->spiders[LEVEL3_SPIDER_0].walls[0].x = 65;
    level_ptr->spiders[LEVEL3_SPIDER_0].walls[0].y = 23;
    level_ptr->spiders[LEVEL3_SPIDER_0].walls[1].x = 71;
    level_ptr->spiders[LEVEL3_SPIDER_0].walls[1].y = 78;
    level_ptr->spiders[LEVEL3_SPIDER_0].walls[2].x = 126;
    level_ptr->spiders[LEVEL3_SPIDER_0].walls[2].y = 71;
    level_ptr->spiders[LEVEL3_SPIDER_0].walls[3].x = 119;
    level_ptr->spiders[LEVEL3_SPIDER_0].walls[3].y = 17;

    level_ptr->spiders[LEVEL3_SPIDER_1].pos.x = 2;
    level_ptr->spiders[LEVEL3_SPIDER_1].pos.y = 8;
    level_ptr->spiders[LEVEL3_SPIDER_1].state.direction = DIRECTION_DOWN;

    level_ptr->spiders[LEVEL3_SPIDER_1].num_walls = 4;
    level_ptr->spiders[LEVEL3_SPIDER_1].walls[0].x = 23;
    level_ptr->spiders[LEVEL3_SPIDER_1].walls[0].y = 126;
    level_ptr->spiders[LEVEL3_SPIDER_1].walls[1].x = 78;
    level_ptr->spiders[LEVEL3_SPIDER_1].walls[1].y = 119;
    level_ptr->spiders[LEVEL3_SPIDER_1].walls[2].x = 71;
    level_ptr->spiders[LEVEL3_SPIDER_1].walls[2].y = 65;
    level_ptr->spiders[LEVEL3_SPIDER_1].walls[3].x = 17;
    level_ptr->spiders[LEVEL3_SPIDER_1].walls[3].y = 72;
}
