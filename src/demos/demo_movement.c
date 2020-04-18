/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/04
 */

/* ===== Includes ===== */
#include <stdio.h>
#include <gb/gb.h>

#include "Droplet.h"
#include "SpriteTileIndex.h"
#include "SpriteSquare16.h"
#include "data\tiles/droplet_sprites.h"

/* ===== MAIN ===== */

int main()
{
    /* Local variables */
    Droplet droplet;
    UINT8 initial_x = 88;
    UINT8 initial_y = 78;

    /* Load sprite data */
    set_sprite_data(0, SPRITE_TILE_COUNT, DropletSprites);

    /* Set Droplet's initial sprite */
    droplet.sprite.top_left = 0;
    droplet.sprite.bottom_left = 1;
    droplet.sprite.top_right = 2;
    droplet.sprite.bottom_right = 3;

    DropletInitialize(&droplet);

    /* Set Droplet's inital location */
    MoveSpriteSquare16(&(droplet.sprite), initial_x, initial_y);

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
