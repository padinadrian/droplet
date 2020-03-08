/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/04
 */

/* ===== Includes ===== */
#include <stdio.h>
#include <gb/gb.h>

#include "tile_data/droplet_sprites.h"

/* ===== Data Types ===== */

#define SPRITE_COUNT 24

typedef enum {
    /* Droplet, 16x16, normal, facing right  */
    SPRITE_DROPLET_16_NORMAL_R_TL   = 8,
    SPRITE_DROPLET_16_NORMAL_R_BL,
    SPRITE_DROPLET_16_NORMAL_R_TR,
    SPRITE_DROPLET_16_NORMAL_R_BR,

    /* Droplet, 16x16, squatting, facing right  */
    SPRITE_DROPLET_16_SQUAT_R_TL    = 12,
    SPRITE_DROPLET_16_SQUAT_R_BL,
    SPRITE_DROPLET_16_SQUAT_R_TR,
    SPRITE_DROPLET_16_SQUAT_R_BR,

    /* Droplet, 16x16, normal, facing left  */
    SPRITE_DROPLET_16_NORMAL_L_TL   = 16,
    SPRITE_DROPLET_16_NORMAL_L_BL,
    SPRITE_DROPLET_16_NORMAL_L_TR,
    SPRITE_DROPLET_16_NORMAL_L_BR,

    /* Droplet, 16x16, squatting, facing left  */
    SPRITE_DROPLET_16_SQUAT_L_TL    = 20,
    SPRITE_DROPLET_16_SQUAT_L_BL,
    SPRITE_DROPLET_16_SQUAT_L_TR,
    SPRITE_DROPLET_16_SQUAT_L_BR
} SpriteIndex;

typedef struct {
    UINT8 top_left;
    UINT8 bottom_left;
    UINT8 top_right;
    UINT8 bottom_right;
} SpriteSquare16;

/* ===== Functions ===== */

/**
 * Set tiles for a 16x16 sprite all at once.
 * Assumes tiles are continuous in the pattern: TL, BL, TR, BR
 */
void SetSpriteTileSquare16(
    SpriteSquare16* sprite,
    UINT8 top_left_tile);

/**
 * Move a 16x16 sprite all at once.
 */
void MoveSpriteSquare16(
    SpriteSquare16* sprite,
    UINT8 x_pos,
    UINT8 y_pos);

/**
 * Scroll a 16x16 sprite all at once.
 */
void ScrollSpriteSquare16(
    SpriteSquare16* sprite,
    UINT8 x_scroll,
    UINT8 y_scroll);

/* ===== MAIN ===== */

int main()
{
    UINT8 counter = 0;
    UINT8 pressed = 0;
    UINT8 squished = 0;
    UINT8 facing_right = 1;
    UINT8 initial_x = 88;
    UINT8 initial_y = 78;
    SpriteSquare16 droplet_sprite;

    /* Load sprite data */
    set_sprite_data(0, SPRITE_COUNT, DropletSprites);

    /* Set Droplet's initial sprite */
    droplet_sprite.top_left = 0;
    droplet_sprite.bottom_left = 1;
    droplet_sprite.top_right = 2;
    droplet_sprite.bottom_right = 3;

    SetSpriteTileSquare16(
        &droplet_sprite,
        SPRITE_DROPLET_16_NORMAL_R_TL
    );

    /* Set Droplet's inital location */
    MoveSpriteSquare16(&droplet_sprite, initial_x, initial_y);

    SHOW_SPRITES;

    while (1) {
        /* Switch between normal and squished */
        counter = (counter < 20) ? counter + 1 : 0;
        squished = (counter < 10);
        SetSpriteTileSquare16(
            &droplet_sprite,
            (
                facing_right ?
                SPRITE_DROPLET_16_NORMAL_R_TL :
                SPRITE_DROPLET_16_NORMAL_L_TL
            ) + (squished * 4)
        );

        /*
        J_LEFT
        J_RIGHT
        J_UP
        J_DOWN
        */
        switch (joypad()) {
            case J_LEFT: {
                if (!pressed) {
                    SetSpriteTileSquare16(&droplet_sprite, SPRITE_DROPLET_16_NORMAL_L_TL);
                    ScrollSpriteSquare16(&droplet_sprite, -8, 0);
                    facing_right = 0;
                    counter = 0;
                    pressed = 1;
                }
                break;
            }
            case J_RIGHT: {
                if (!pressed) {
                    SetSpriteTileSquare16(&droplet_sprite, SPRITE_DROPLET_16_NORMAL_R_TL);
                    ScrollSpriteSquare16(&droplet_sprite, 8, 0);
                    facing_right = 1;
                    counter = 0;
                    pressed = 1;
                }
                break;
            }
            case J_UP: {
                if (!pressed) {
                    SetSpriteTileSquare16(
                        &droplet_sprite,
                        (
                            facing_right ?
                            SPRITE_DROPLET_16_NORMAL_R_TL :
                            SPRITE_DROPLET_16_NORMAL_L_TL
                        )
                    );
                    ScrollSpriteSquare16(&droplet_sprite, 0, -8);
                    counter = 0;
                    pressed = 1;
                }
                break;
            }
            case J_DOWN: {
                if (!pressed) {
                    SetSpriteTileSquare16(
                        &droplet_sprite,
                        (
                            facing_right ?
                            SPRITE_DROPLET_16_NORMAL_R_TL :
                            SPRITE_DROPLET_16_NORMAL_L_TL
                        )
                    );
                    ScrollSpriteSquare16(&droplet_sprite, 0, 8);
                    counter = 0;
                    pressed = 1;
                }
                break;
            }
            default: {
                pressed = 0;
                break;
            }
        }

        delay(50);
    }

    return 0;
}

/**
 * Set tiles for a 16x16 sprite all at once.
 * Assumes tiles are continuous in the pattern: TL, BL, TR, BR
 */
void SetSpriteTileSquare16(
        SpriteSquare16* sprite,
        UINT8 top_left_tile)
{
    /* set_sprite_tile(<sprite_id>, <sprite_data_index>); */
    set_sprite_tile(sprite->top_left,     top_left_tile);
    set_sprite_tile(sprite->bottom_left,  top_left_tile + 1);
    set_sprite_tile(sprite->top_right,    top_left_tile + 2);
    set_sprite_tile(sprite->bottom_right, top_left_tile + 3);
}

/**
 * Move a 16x16 sprite all at once.
 */
void MoveSpriteSquare16(
        SpriteSquare16* sprite,
        UINT8 x_pos,
        UINT8 y_pos)
{
    /* set_sprite_tile(<sprite_id>, <sprite_data_index>); */
    move_sprite(sprite->top_left,     x_pos + 0, y_pos + 0);
    move_sprite(sprite->bottom_left,  x_pos + 0, y_pos + 8);
    move_sprite(sprite->top_right,    x_pos + 8, y_pos + 0);
    move_sprite(sprite->bottom_right, x_pos + 8, y_pos + 8);
}

/**
 * Scroll a 16x16 sprite all at once.
 */
void ScrollSpriteSquare16(
    SpriteSquare16* sprite,
    UINT8 x_scroll,
    UINT8 y_scroll)
{
    /* set_sprite_tile(<sprite_id>, <sprite_data_index>); */
    scroll_sprite(sprite->top_left,     x_scroll, y_scroll);
    scroll_sprite(sprite->bottom_left,  x_scroll, y_scroll);
    scroll_sprite(sprite->top_right,    x_scroll, y_scroll);
    scroll_sprite(sprite->bottom_right, x_scroll, y_scroll);
}