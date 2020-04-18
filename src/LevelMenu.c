/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

/* ===== Includes ===== */
#include "LevelMenu.h"
#include "Level.h"
#include "data/maps/droplet_level1_bg.h"

/* ===== Data ===== */

Level level_list[2];

/* ===== Functions ===== */

/**
 * 
 */
void LevelMenu()
{
    UINT8 level_number = 1;

    /* TODO: Abstract this out somewhere else. (game init?) */
    SetLevelBackground(
        &level_list[1],
        DropletBackgroundLevel1,
        DropletBackgroundLevel1Width,
        DropletBackgroundLevel1Height
    );

    level_list[1].droplet_start_pos.x = 1;
    level_list[1].droplet_start_pos.x = 10;

    PlayLevel(&level_list[level_number]);
}

/**
 * 
 */
void PlayLevel(Level* level_ptr)
{
    UINT8 joypad_input;
    Droplet droplet;
    Position* droplet_pos_ptr = &(droplet.pos);

    LoadLevel(level_ptr);

    // while (!IsLevelComplete(level_ptr, droplet_pos_ptr))
    while (1)
    {
        /* Switch between normal and squished. */
        DropletAnimate(&droplet);

        /* TODO: Move enemies and check for collision. */

        /* Move Droplet around the screen. */
        joypad_input = joypad();
        MoveDroplet(&droplet, joypad_input, &(level_ptr->level_map));

        /* TODO: Toggle switches. */

        /* Loop time of ~50ms */
        delay(50);
    }
}


