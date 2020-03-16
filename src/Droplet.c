/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/08
 */

/* ===== Includes ===== */
#include <stdio.h>
#include <gb/gb.h>
#include "Droplet.h"
#include "SpriteTileIndex.h"

/* ===== Definitions ===== */
#define LOOP_TIME 50        /* TODO: Define this in a header somewhere. */
#define SQUAT_PERIOD 1000   /* Have Droplet squat once per second. */
#define MAX_COUNTER 20
#define HALF_COUNTER (MAX_COUNTER/2)

/* ===== Functions ===== */

/**
 * Initialize Droplet sprite and data.
 */
void DropletInitialize(DropletSprite* droplet_ptr)
{
    droplet_ptr->squat_counter = 0;
    droplet_ptr->squatting = 0;
    droplet_ptr->facing_right = 1;
    droplet_ptr->pressed = 0;

    /* Droplet starts off in normal position facing right. */
    SetSpriteTileSquare16(
        &droplet_ptr->sprite,
        SPRITE_DROPLET_16_NORMAL_R_TL
    );
}

/**
 * Animate Droplet squatting when he is idle.
 * This function should be called once per game loop.
 */
void DropletAnimate(DropletSprite* droplet_ptr)
{
    UINT8 counter = 0;
    UINT8 squatting = 0;

    /* Check squatting rollover counter. */
    counter = droplet_ptr->squat_counter;
    droplet_ptr->squat_counter = (counter < MAX_COUNTER) ? counter + 1 : 0;
    droplet_ptr->squatting = squatting = (counter < HALF_COUNTER);

    SetSpriteTileSquare16(
        &droplet_ptr->sprite,
        (
            droplet_ptr->facing_right ?
            SPRITE_DROPLET_16_NORMAL_R_TL :
            SPRITE_DROPLET_16_NORMAL_L_TL
        ) + (squatting * 4)
    );
}

/**
 * Helper function - check edge detection before moving sprite.
 */
int DropletCheckMovement(
    UINT8 joypad_input,
    Position* cur_pos_ptr,
    DropletMap* map_ptr
)
{
    printf(
        "x: %c, y: %c, dir: %c\n",
        ((unsigned char)cur_pos_ptr->x & 15) + '0',
        ((unsigned char)cur_pos_ptr->y & 15) + '0',
        (unsigned char)joypad_input + '0'
    );
    switch (joypad_input)
    {
        case J_LEFT:
            return !TileIsWall(
                map_ptr,
                cur_pos_ptr->x - 1,
                cur_pos_ptr->y
            );
        case J_RIGHT:
            return !TileIsWall(
                map_ptr,
                cur_pos_ptr->x + 2,
                cur_pos_ptr->y
            );
        case J_UP:
            return !TileIsWall(
                map_ptr,
                cur_pos_ptr->x,
                cur_pos_ptr->y - 1
            );
        case J_DOWN:
            return !TileIsWall(
                map_ptr,
                cur_pos_ptr->x,
                cur_pos_ptr->y + 2
            );
        default:
            return 0;
    }
}

/**
 * Move the Droplet sprite in the desired direction.
 */
void MoveDroplet(
    DropletSprite* droplet_ptr,
    UINT8 direction,
    DropletMap* map_ptr
)
{
    switch (direction) {
        case J_LEFT: {
            if (!droplet_ptr->pressed &&
                DropletCheckMovement(
                    direction,
                    &droplet_ptr->pos,
                    map_ptr
                )
            )
            {
                droplet_ptr->pos.x -= 1;
                SetSpriteTileSquare16(
                    &droplet_ptr->sprite,
                    SPRITE_DROPLET_16_NORMAL_L_TL
                );
                ScrollSpriteSquare16(&droplet_ptr->sprite, -8, 0);
                droplet_ptr->facing_right = 0;
                droplet_ptr->squat_counter = 0;
                droplet_ptr->pressed = 1;
            }
            break;
        }
        case J_RIGHT: {
            if (!droplet_ptr->pressed &&
                DropletCheckMovement(
                    direction,
                    &droplet_ptr->pos,
                    map_ptr
                )
            )
            {
                droplet_ptr->pos.x += 1;
                SetSpriteTileSquare16(
                    &droplet_ptr->sprite,
                    SPRITE_DROPLET_16_NORMAL_R_TL
                );
                ScrollSpriteSquare16(&droplet_ptr->sprite, 8, 0);
                droplet_ptr->facing_right = 1;
                droplet_ptr->squat_counter = 0;
                droplet_ptr->pressed = 1;
            }
            break;
        }
        case J_UP: {
            if (!droplet_ptr->pressed &&
                DropletCheckMovement(
                    direction,
                    &droplet_ptr->pos,
                    map_ptr
                )
            )
            {
                droplet_ptr->pos.y -= 1;
                SetSpriteTileSquare16(
                    &droplet_ptr->sprite,
                    (
                        droplet_ptr->facing_right ?
                        SPRITE_DROPLET_16_NORMAL_R_TL :
                        SPRITE_DROPLET_16_NORMAL_L_TL
                    )
                );
                ScrollSpriteSquare16(&droplet_ptr->sprite, 0, -8);
                droplet_ptr->squat_counter = 0;
                droplet_ptr->pressed = 1;
            }
            break;
        }
        case J_DOWN: {
            if (!droplet_ptr->pressed &&
                DropletCheckMovement(
                    direction,
                    &droplet_ptr->pos,
                    map_ptr
                )
            )
            {
                droplet_ptr->pos.y += 1;
                SetSpriteTileSquare16(
                    &droplet_ptr->sprite,
                    (
                        droplet_ptr->facing_right ?
                        SPRITE_DROPLET_16_NORMAL_R_TL :
                        SPRITE_DROPLET_16_NORMAL_L_TL
                    )
                );
                ScrollSpriteSquare16(&droplet_ptr->sprite, 0, 8);
                droplet_ptr->squat_counter = 0;
                droplet_ptr->pressed = 1;
            }
            break;
        }
        default: {
            droplet_ptr->pressed = 0;
            break;
        }
    }
}
