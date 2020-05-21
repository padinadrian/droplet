/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/25
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Levels.h"
#include "Gate.h"
#include "Switch.h"
#include "Droplet.h"
#include "Sprites.h"
#include "Position.h"
#include "SpriteSquare16.h"
#include "SpriteTileIndex.h"
#include "BackgroundTileIndex.h"
#include "data/tiles/droplet_background_tiles.h"
#include "data/maps/droplet_level2_bg.h"

/* ===== Data ===== */

enum { NUM_LEVELS = 2 };
static LevelFunction level_list[NUM_LEVELS];

#include "Level1.h"

/** LEVEL 2 **/
/**
 * TODO: Move this to a proper data file instead of living
 * in a source file.
 */
/*
enum { LEVEL2_NUM_GATES = 6 };
enum { LEVEL2_NUM_SWITCHES = 6 };
enum { LEVEL2_NUM_GATESWITCHES = 6 };
void InitializeLevel2(Level* level_ptr)
{
    /* Gates and Switches
    static Gate gates[LEVEL2_NUM_GATES];
    static Switch switches[LEVEL2_NUM_SWITCHES];
    static GateSwitch gateswitches[LEVEL2_NUM_GATESWITCHES];

    SetLevelBackground(
        level_ptr,
        DropletBackgroundLevel2,
        DropletBackgroundLevel2Width,
        DropletBackgroundLevel2Height
    );

    level_ptr->droplet_start_pos.x = 1;
    level_ptr->droplet_start_pos.y = 8;
    level_ptr->exit_pos.x = 17;
    level_ptr->exit_pos.y = 8;

    /* Switches

    switches[0].state = SWITCH_OFF;
    switches[0].pos.x = (5 << 3) + 4;
    switches[0].pos.y = (3 << 3);

    switches[1].state = SWITCH_OFF;
    switches[1].pos.x = (9 << 3) + 4;
    switches[1].pos.y = (3 << 3);

    switches[2].state = SWITCH_OFF;
    switches[2].pos.x = (13 << 3) + 4;
    switches[2].pos.y = (3 << 3);

    switches[3].state = SWITCH_OFF;
    switches[3].pos.x = (5 << 3) + 4;
    switches[3].pos.y = (3 << 3);

    switches[4].state = SWITCH_OFF;
    switches[4].pos.x = (5 << 3) + 4;
    switches[4].pos.y = (3 << 3);

    switches[5].state = SWITCH_OFF;
    switches[5].pos.x = (5 << 3) + 4;
    switches[5].pos.y = (3 << 3);
}
*/

/* ===== Functions ===== */

/** Initialize all levels. */
void InitializeLevels()
{
    level_list[1] = InitializeLevel1;
}

/** Load the level. */
void LoadLevel(
        Level* level_ptr,
        Droplet* droplet_ptr)
{
    UINT8 i;
    Position droplet_pixel_pos;

    set_bkg_data(0, BG_TILE_COUNT, DropletBkgTiles);
    SetBackground(&(level_ptr->level_map));

    ClearExistingSprites();
    DropletInitialize(droplet_ptr, &level_ptr->droplet_start_pos);

    /* Move Droplet to the starting position. */
    droplet_pixel_pos.x = droplet_ptr->pos.x;
    droplet_pixel_pos.y = droplet_ptr->pos.y;

    GridPosToPixelPos(&droplet_pixel_pos);
    MoveSpriteSquare16(
        &(droplet_ptr->sprite),
        droplet_pixel_pos.x,
        droplet_pixel_pos.y
    );

    /* Initialize gates and switches. */
    for (i = 0; i < level_ptr->num_switches; ++i) {
        level_ptr->switches[i].sprite = NewSpriteID();
        MoveSprite(
            level_ptr->switches[i].sprite,
            level_ptr->switches[i].pos.x,
            level_ptr->switches[i].pos.y
        );
    }

    for (i = 0; i < level_ptr->num_gates; ++i) {
        level_ptr->gates[i].sprite = NewSpriteID();
        MoveSprite(
            level_ptr->gates[i].sprite,
            level_ptr->gates[i].pos.x,
            level_ptr->gates[i].pos.y
        );
    }

    SHOW_SPRITES;
    SHOW_BKG;
}

/** Load the level and play it. */
void PlayLevel(UINT8 level_number)
{
    UINT8 joypad_input = 0;
    UINT8 a_pressed = 0;
    Droplet droplet;
    Position* droplet_pos_ptr = &(droplet.pos);
    static Level level;
    Level* level_ptr = &level;

    level_list[level_number](level_ptr);

    LoadLevel(level_ptr, &droplet);

    while (!IsLevelComplete(level_ptr, droplet_pos_ptr))
    {
        /* Switch between normal and squished. */
        DropletAnimate(&droplet);

        /* TODO: Move enemies and check for collision. */

        /* Move Droplet around the screen. */
        joypad_input = joypad();
        if (DropletCheckMovement(level_ptr, &droplet, joypad_input)) {
            MoveDroplet(&droplet, joypad_input);
        }

        if (joypad_input & J_A) {
            if (!a_pressed) {
                a_pressed = 1;
                FlipNearbySwitches(
                    level_ptr->switches,
                    level_ptr->num_switches,
                    droplet_pos_ptr
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

        /* Loop time of ~50ms */
        delay(50);
    }

    ClearExistingSprites();
}
