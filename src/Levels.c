/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-04-25
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "levels/Levels.h"
#include "objects/Gate.h"
#include "objects/Droplet.h"
#include "Position.h"
#include "Sprites.h"
#include "SpriteSquare16.h"
#include "SpriteTileIndex.h"
#include "BackgroundTileIndex.h"
#include "data/tiles/droplet_background_tiles.h"

/* ===== Data ===== */

// Lookup table for level init function pointers.
static LevelFunction level_functions[NUM_LEVELS] = {
    InitializeLevel1,
    InitializeLevel2,
    InitializeLevel3,
};

// Global level instance for the current level.
static Level global_level;

/* ===== Functions ===== */

/** Load the level. */
void LoadLevel(Level* level_ptr)
{
    UINT8 i;

    SWITCH_ROM_MBC1(1);
    set_bkg_data(BACKGROUND_TILE_START, NUM_BACKGROUND_TILES, DropletBkgTiles);

    SWITCH_ROM_MBC1(3);
    SetBackground(&(level_ptr->level_map));

    ClearExistingSprites();
    DropletInitialize(level_ptr->start_pos);

    /* Initialize gates and switches. */
    for (i = 0; i < level_ptr->num_switches; ++i) {
        InitializeSwitch(&level_ptr->switches[i]);
    }
    for (i = 0; i < level_ptr->num_gates; ++i) {
        InitializGate(&level_ptr->gates[i]);
    }

    /* Initialize spiders. */
    for (i = 0; i < level_ptr->num_spiders; ++i) {
        SpiderInitialize(&(level_ptr->spiders[i]));
    }

    SHOW_SPRITES;
    SHOW_BKG;
}

/** Load the level and play it. */
void PlayLevel(UINT8 level_number)
{
    UINT8 i;
    UINT8 joypad_input = 0;
    UINT8 a_pressed = 0;
    Position* droplet_pos_ptr = &(droplet_global.pos);
    Level* level_ptr = &global_level;

    ResetLevel(level_ptr);

    /* TODO: Mapping from level number to ROM bank number. */
    SWITCH_ROM_MBC1(3);
    level_functions[level_number](level_ptr);
    LoadLevel(level_ptr);

    while (!IsLevelComplete(level_ptr, droplet_pos_ptr))
    {
        /* Switch between normal and squished. */
        DropletAnimate();

        /* Move Droplet around the screen. */
        joypad_input = joypad();
        if (DropletCheckMovement(level_ptr, joypad_input)) {
            MoveDroplet(joypad_input);
        }

        if (joypad_input & J_A) {
            if (!a_pressed) {
                a_pressed = 1;
                FlipNearbySwitches(
                    level_ptr->switches,
                    level_ptr->num_switches,
                    *droplet_pos_ptr
                );
                CheckGateSwitches(
                    level_ptr->gates,
                    level_ptr->num_gates,
                    level_ptr->switches
                );
            }
        }
        else {
            a_pressed = 0;
        }

        /* Move enemies and check for collision. */
        for (i = 0; i < level_ptr->num_spiders; ++i) {
            UpdateSpider(&(level_ptr->spiders[i]));
        }

        /* Loop time of ~50ms */
        delay(50);
    }

    ClearExistingSprites();
}
