/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/04
 */

/* ===== Includes ===== */
#include <stdio.h>
#include <string.h>
#include <gb/gb.h>
#include "data/tiles/droplet_sprites.h"
#include "data/tiles/droplet_background_tiles.h"
#include "BackgroundTileIndex.h"
#include "SpriteManager.h"
#include "SpriteTileIndex.h"
#include "LevelMenu.h"
#include "Levels.h"
#include "Splash.h"

/* ===== MAIN ===== */

int main()
{
    /* Display static Loading screen. */

    /* Initialize tile data. */
    set_sprite_data(0, SPRITE_TILE_COUNT, DropletSprites);
    set_bkg_data(0, BG_TILE_COUNT, DropletBkgTiles);

    /* Initialize internal data. */
    InitializeSpriteCounter();
    InitializeLevels();

    while (1)
    {
        /* Display splash screen. */
        /* "PRESS START" */
        Splash();

        /* Save file select. */

        /* Load save file. */

        /* Level select. */
        LevelMenu();

        /* TODO: Remove later. */
        printf("Done");
        delay(5000);
    }

    return 0;
}
