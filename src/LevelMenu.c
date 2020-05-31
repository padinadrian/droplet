/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "LevelMenu.h"
#include "Levels.h"
#include "Sprites.h"
#include "LevelSelector.h"
#include "SpriteTileIndex.h"
#include "BackgroundTileIndex.h"
#include "data/tiles/droplet_background_tiles.h"
#include "data/maps/droplet_level_menu_bg.h"

/* ===== Functions ===== */


static UINT8 JoypadChanges(UINT8 input)
{
    static UINT8 state = 0;
    UINT8 changes = input & ~state;
    state = input;
    return changes;
}

/**
 * Display level-picking menu.
 */
void LevelMenu()
{
    static LevelSelector selector;
    UINT8 joypad_input = 0;

    HIDE_BKG;
    HIDE_SPRITES;

    set_bkg_data(0, BG_TILE_COUNT, DropletBkgTiles);
    set_bkg_tiles(
        0,
        0,
        DropletBackgroundLevelMenuWidth,
        DropletBackgroundLevelMenuHeight,
        DropletBackgroundLevelMenu
    );

    ClearExistingSprites();
    InitializeSelector(&selector);
    // UINT8 level_number = 2;
    // PlayLevel(level_number);

    SHOW_BKG;
    SHOW_SPRITES;

    while (1) {
        /* TODO: Select level */
        joypad_input = JoypadChanges(joypad());
        if (joypad_input > 0) {
            MoveSelector(&selector, joypad_input);
        }
        delay(50);
    }
}
