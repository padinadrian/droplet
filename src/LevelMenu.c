/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "LevelMenu.h"
#include "Levels.h"
#include "Sprites.h"
#include "Utility.h"
#include "LevelSelector.h"
#include "SpriteTileIndex.h"
#include "BackgroundTileIndex.h"
#include "data/tiles/droplet_level_menu_tiles.h"
#include "data/maps/droplet_level_menu_bg.h"

/* ===== Functions ===== */

/**
 * Display level-picking menu.
 */
UINT8 LevelMenu()
{
    static LevelSelector selector;
    UINT8 joypad_input = 0;
    UINT8 level_number = 0;

    HIDE_BKG;
    HIDE_SPRITES;

    set_bkg_data(
        BACKGROUND_TILE_START,
        NUM_LEVEL_MENU_TILES,
        DropletMenuTiles
    );
    set_bkg_tiles(
        0,
        0,
        DropletBackgroundLevelMenuWidth,
        DropletBackgroundLevelMenuHeight,
        DropletBackgroundLevelMenu
    );

    ClearExistingSprites();
    InitializeSelector(&selector);

    SHOW_BKG;
    SHOW_SPRITES;

    waitpadup();

    while (0 == level_number) {
        /* Poll the joypad for input changes. */
        joypad_input = JoypadChanges(joypad());
        if (joypad_input) {

            /* Move the selector icon. */
            MoveSelector(&selector, joypad_input);

            /* Select a level. */
            if (joypad_input & (J_A | J_START)) {
                level_number = SelectLevel(&selector);
            }
        }
        delay(50);
    }

    return level_number;
}
