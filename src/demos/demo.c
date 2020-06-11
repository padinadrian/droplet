/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/04
 */

/* ===== Includes ===== */
#include <stdio.h>
#include <string.h>
#include <gb/gb.h>

#include "Droplet.h"
#include "BackgroundTileIndex.h"
#include "SpriteTileIndex.h"

#include "data/tiles/droplet_sprites.c"
#include "data/tiles/droplet_background_tiles.c"
#include "data/maps/droplet_level1_bg.c"

/* ===== MAIN ===== */

int demo()
{
    /* Local variables */
    Droplet droplet;
    BackgroundMap level1_map;
    Position droplet_pixel_pos;
    int i, j;
    UINT8 joypad_input = 0;

    level1_map.map_data = DropletBackgroundLevel1;
    level1_map.width = DropletBackgroundLevel1Width;
    level1_map.height = DropletBackgroundLevel1Height;

    for (i = 0; i < level1_map.width; i++)
    {
        for (j = 0; j < level1_map.height; j++)
        {
            level1_map.map_data[i * level1_map.width + j] = 0;
        }
    }

    droplet.pos.x = 1;
    droplet.pos.y = 10;

    /* Load sprite data */
    set_sprite_data(0, SPRITE_TILE_COUNT, DropletSprites);
    set_bkg_data(BACKGROUND_TILE_START, NUM_BACKGROUND_TILES, DropletBkgTiles);
    set_bkg_tiles(
        0,
        0,
        DropletBackgroundLevel1Width,
        DropletBackgroundLevel1Height,
        DropletBackgroundLevel1
    );

    /* Set Droplet's initial sprite */
    droplet.sprite.top_left = 0;
    droplet.sprite.bottom_left = 1;
    droplet.sprite.top_right = 2;
    droplet.sprite.bottom_right = 3;

    DropletInitialize(&droplet);

    /* Set Droplet's inital location */
    droplet_pixel_pos.x = droplet.pos.x;
    droplet_pixel_pos.y = droplet.pos.y;
    GridPosToPixelPos(&droplet_pixel_pos);
    MoveSpriteSquare16(
        &(droplet.sprite),
        droplet_pixel_pos.x,
        droplet_pixel_pos.y
    );

    // SHOW_BKG;
    SHOW_SPRITES;
    SHOW_BKG;

    while (1) {
        /* Switch between normal and squished. */
        DropletAnimate(&droplet);

        /* Move Droplet around the screen. */
        joypad_input = joypad();
        MoveDroplet(&droplet, joypad_input, &level1_map);

        /* Loop time of ~50ms */
        delay(50);
    }

    return 0;
}
