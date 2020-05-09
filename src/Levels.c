/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/25
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Levels.h"
#include "Gate.h"
#include "Droplet.h"
#include "Position.h"
#include "Sprites.h"
#include "SpriteSquare16.h"
#include "SpriteTileIndex.h"
#include "BackgroundTileIndex.h"
#include "data/tiles/droplet_background_tiles.h"
#include "data/maps/droplet_level1_bg.h"

/* ===== Data ===== */

enum { NUM_LEVELS = 2 };
static Level level_list[NUM_LEVELS];

/* ===== LEVELS ===== */

/** LEVEL 1 **/
/**
 * TODO: Move this to a proper data file instead of living
 * in a source file.
 */
enum { LEVEL1_NUM_SWITCHES = 3 };
enum { LEVEL1_NUM_GATES = 6 };
void InitializeLevel1(Level* level_ptr)
{
    /* Gates and Switches */
    static Switch switches[LEVEL1_NUM_SWITCHES];
    static Gate gates[LEVEL1_NUM_GATES];
    static GateSwitch gateswitch1;
    static GateSwitch gateswitch2;
    static GateSwitch gateswitch3;

    SetLevelBackground(
        level_ptr,
        DropletBackgroundLevel1,
        DropletBackgroundLevel1Width,
        DropletBackgroundLevel1Height
    );

    level_ptr->droplet_start_pos.x = 1;
    level_ptr->droplet_start_pos.y = 10;
    level_ptr->exit_pos.x = 17;
    level_ptr->exit_pos.y = 10;

    switches[0].state = SWITCH_OFF;
    switches[0].pos.x = (5 << 3) + 4;
    switches[0].pos.y = (5 << 3);

    switches[1].state = SWITCH_OFF;
    switches[1].pos.x = (9 << 3) + 4;
    switches[1].pos.y = (5 << 3);

    switches[2].state = SWITCH_OFF;
    switches[2].pos.x = (13 << 3) + 4;
    switches[2].pos.y = (5 << 3);

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

    level_ptr->switches = &switches;
    level_ptr->gates = &gates;

    gateswitch1.switch_index = 0;
    gateswitch1.trigger_state = SWITCH_ON;
    gateswitch2.switch_index = 1;
    gateswitch2.trigger_state = SWITCH_ON;
    gateswitch3.switch_index = 2;
    gateswitch3.trigger_state = SWITCH_ON;

    gates[0].switches = &gateswitch1;
    gates[0].num_switches = 1;
    gates[1].switches = &gateswitch1;
    gates[1].num_switches = 1;

    gates[2].switches = &gateswitch2;
    gates[2].num_switches = 1;
    gates[3].switches = &gateswitch2;
    gates[3].num_switches = 1;

    gates[4].switches = &gateswitch3;
    gates[4].num_switches = 1;
    gates[5].switches = &gateswitch3;
    gates[5].num_switches = 1;

    level_ptr->num_switches = LEVEL1_NUM_SWITCHES;
    level_ptr->num_gates = LEVEL1_NUM_GATES;
}

/* ===== Functions ===== */

/** Initialize all levels. */
void InitializeLevels()
{
    InitializeLevel1(&level_list[1]);
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
        SetSwitchState(
            &(level_ptr->switches[i]),
            level_ptr->switches[i].state
        );
    }

    for (i = 0; i < level_ptr->num_gates; ++i) {
        level_ptr->gates[i].sprite = NewSpriteID();
        MoveSprite(
            level_ptr->gates[i].sprite,
            level_ptr->gates[i].pos.x,
            level_ptr->gates[i].pos.y
        );
        SetGateState(
            &(level_ptr->gates[i]),
            level_ptr->gates[i].state
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
    Level* level_ptr = &level_list[level_number];

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
