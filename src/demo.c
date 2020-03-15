/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/04
 */

/* ===== Includes ===== */
#include <stdio.h>
#include <gb/gb.h>

#include "Droplet.h"
#include "BackgroundTileIndex.h"
#include "SpriteTileIndex.h"
#include "tile_data\droplet_sprites.c"
#include "tile_data\droplet_background_tiles.c"
#include "map_data\droplet_level1_bg.c"

typedef struct {
    UINT8 x;
    UINT8 y;
} Position;

void GridPosToPixelPos(Position* grid_pos)
{

}

/* ===== MAIN ===== */

int main()
{
    /* Local variables */
    DropletSprite droplet;
    UINT8 initial_x = 80;
    UINT8 initial_y = 79;


    /* Load sprite data */
    set_sprite_data(0, SPRITE_TILE_COUNT, DropletSprites);
    set_bkg_data(0, BG_TILE_COUNT, DropletBkgTiles);
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
    MoveSpriteSquare16(&(droplet.sprite), initial_x, initial_y);

    SHOW_BKG;
    SHOW_SPRITES;

    while (1) {
        /* Switch between normal and squished. */
        DropletAnimate(&droplet);

        /* Move Droplet around the screen. */
        MoveDroplet(&droplet, joypad());

        /* Loop time of ~50ms */
        delay(50);
    }

    return 0;
}
