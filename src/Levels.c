/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/25
 */

/* ===== Includes ===== */
#include "Levels.h"
#include "Droplet.h"
#include "Position.h"
#include "SpriteManager.h"
#include "SpriteSquare16.h"
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
void InitializeLevel1(Level* level_ptr)
{
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

    SHOW_SPRITES;
    SHOW_BKG;
}

/** Load the level and play it. */
void PlayLevel(UINT8 level_number)
{
    UINT8 joypad_input = 0;
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
        MoveDroplet(&droplet, joypad_input, &(level_ptr->level_map));

        /* TODO: Toggle switches. */

        /* Loop time of ~50ms */
        delay(50);
    }

    ClearExistingSprites();
}
