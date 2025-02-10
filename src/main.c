/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-04
 */

/* ===== Includes ===== */
#include <stdio.h>
#include <string.h>
#include <gb/gb.h>
#include "data/tiles/droplet_sprites.h"
#include "data/tiles/droplet_background_tiles.h"
#include "levels/Levels.h"
#include "BackgroundTileIndex.h"
#include "Sprites.h"
#include "SpriteTileIndex.h"
#include "LevelMenu.h"
#include "Splash.h"

/* ===== MAIN ===== */

int main()
{
    /* Local variables. */
    UINT8 level_number = 0;

    /* Display static loading screen. */
    /* "Nintendo(c)" */

    /* Display splash screen. */
    /* "PRESS START" */
    Splash();

    /* Initialize internal data. */
    InitializeSpriteCounter();

    /* Initialize sprite tile data. */
    set_sprite_data(0, SPRITE_TILE_COUNT, DropletSprites);

    while (1) {

        /* TODO: Save file select. */

        /* TODO: Load save file. */

        /* Level select. */
        SWITCH_ROM_MBC1(2);
        level_number = LevelMenu();

        SWITCH_ROM_MBC1(1);
        if (level_number < NUM_LEVELS) {
            PlayLevel(level_number);
        }
        else {
            SWITCH_ROM_MBC1(1);
            printf("bad level number %d!\n", level_number);
        }

        /* TODO: Remove later. */
        printf("Press start...\n");
        waitpad(J_START);

        /* delay(5000); */
    }

    return 0;
}
