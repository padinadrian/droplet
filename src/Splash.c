/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/23
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "data/maps/droplet_splash_bg.h"
#include "data/tiles/droplet_splash_tiles.h"
#include "data/tiles/droplet_sprites.h"
#include "src/SpriteTileIndex.h"


void Splash()
{
    UINT8 row = 0;
    UINT8 col = 0;
    UINT8 i = 0;
    const UINT8 NUM_RAINDROPS = 32;

    /* Initialize background */
    set_bkg_data(0, 86, DropletSplashTiles);
    set_bkg_tiles(
        0,
        0,
        DropletSplashBackgroundWidth,
        DropletSplashBackgroundHeight,
        DropletSplashBackground
    );

    /* Initialize sprites */
    set_sprite_data(0, SPRITE_TILE_COUNT, DropletSprites);
    for (i = 0; i < NUM_RAINDROPS; i++)
    {
        set_sprite_tile(i, SPRITE_RAIN_PHASE_1);
    }

    move_sprite(0,  0x00, 0x00);
    move_sprite(1,  0x40, 0x00);
    move_sprite(2,  0x80, 0x00);
    move_sprite(3,  0xC0, 0x00);

    move_sprite(4,  0x10, 0x20);
    move_sprite(5,  0x40, 0x20);
    move_sprite(6,  0x90, 0x20);
    move_sprite(7,  0xC0, 0x20);

    move_sprite(8,  0x20, 0x40);
    move_sprite(9,  0x60, 0x40);
    move_sprite(10, 0xA0, 0x40);
    move_sprite(11, 0xE0, 0x40);

    move_sprite(12, 0x00, 0x60);
    move_sprite(13, 0x30, 0x60);
    move_sprite(14, 0x80, 0x60);
    move_sprite(15, 0xB0, 0x60);

    move_sprite(16, 0x00, 0x80);
    move_sprite(17, 0x40, 0x80);
    move_sprite(18, 0x80, 0x80);
    move_sprite(19, 0xC0, 0x80);

    move_sprite(20, 0x10, 0xA0);
    move_sprite(21, 0x40, 0xA0);
    move_sprite(22, 0x90, 0xA0);
    move_sprite(23, 0xC0, 0xA0);

    move_sprite(24, 0x20, 0xC0);
    move_sprite(25, 0x60, 0xC0);
    move_sprite(26, 0xA0, 0xC0);
    move_sprite(27, 0xE0, 0xC0);

    move_sprite(28, 0x00, 0xE0);
    move_sprite(29, 0x30, 0xE0);
    move_sprite(30, 0x80, 0xE0);
    move_sprite(31, 0xB0, 0xE0);

    SHOW_BKG;
    SHOW_SPRITES;

    while (!(joypad() & (J_A | J_START)))
    {
        for (i = 0; i < NUM_RAINDROPS; i++)
        {
            scroll_sprite(i, -8, 16);
        }
        delay(50);
    }
}