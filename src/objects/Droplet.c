/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-08
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "objects/Droplet.h"
#include "SpriteTileIndex.h"
#include "Sprites.h"
#include "Utility.h"

/* ===== Definitions ===== */

// The animation states of Droplet.
typedef enum {
    DROPLET_STATE_NORMAL_RIGHT,
    DROPLET_STATE_NORMAL_LEFT,
    DROPLET_STATE_SQUAT_RIGHT,
    DROPLET_STATE_SQUAT_LEFT,
    NUM_DROPLET_STATES,
} DropletState;

enum { DROPLET_COUNTER_MAX = 30 };

// Global Droplet instance.
Droplet droplet_global;

/* ===== Functions ===== */

/**
 * Initialize Droplet sprite and data.
 */
void DropletInitialize(Position start_pos)
{
    Position droplet_pixel_pos;

    /* Reset status flags and counters. */
    droplet_global.state = DROPLET_STATE_NORMAL_RIGHT;
    droplet_global.state_counter = 0;
    droplet_global.pressed = 0;

    /* Set sprite IDs. */
    SpriteSquare16* sprite_ptr = &(droplet_global.sprite);
    InitializeSpriteSquare16(sprite_ptr);

    /* Droplet starts off in normal position facing right. */
    SetSpriteTileSquare16(
        sprite_ptr,
        (UINT8)SPRITE_DROPLET_16_NORMAL_TL
    );

    /* Move Droplet to the starting position. */
    PositionCopy(&droplet_pixel_pos, start_pos);

    GridPosToPixelPos(&droplet_pixel_pos);
    MoveSpriteSquare16(
        &(droplet_global.sprite),
        droplet_pixel_pos.x,
        droplet_pixel_pos.y
    );

    PositionCopy(&droplet_global.pos, start_pos);
}

/**
 * Animate Droplet squatting when he is idle.
 * This function should be called once per game loop.
 */
void DropletAnimate()
{
    // Update state counter
    UINT8 counter = IncrementRollover(droplet_global.state_counter, DROPLET_COUNTER_MAX);
    droplet_global.state_counter = counter;

    if (counter == 0) {
        switch (droplet_global.state) {
            // Normal state
            case DROPLET_STATE_NORMAL_RIGHT: {
                droplet_global.state = DROPLET_STATE_SQUAT_RIGHT;
                SetSpriteTileSquare16(
                    &droplet_global.sprite,
                    (UINT8)SPRITE_DROPLET_16_SQUAT_TL
                );
                break;
            }
            case DROPLET_STATE_NORMAL_LEFT: {
                droplet_global.state = DROPLET_STATE_SQUAT_LEFT;
                SetSpriteTileSquare16(
                    &droplet_global.sprite,
                    (UINT8)SPRITE_DROPLET_16_SQUAT_TL
                );
                break;
            }
            // Squatting state
            case DROPLET_STATE_SQUAT_RIGHT:{
                droplet_global.state = DROPLET_STATE_NORMAL_RIGHT;
                SetSpriteTileSquare16(
                    &droplet_global.sprite,
                    (UINT8)SPRITE_DROPLET_16_NORMAL_TL
                );
                break;
            }
            case DROPLET_STATE_SQUAT_LEFT: {
                droplet_global.state = DROPLET_STATE_NORMAL_LEFT;
                SetSpriteTileSquare16(
                    &droplet_global.sprite,
                    (UINT8)SPRITE_DROPLET_16_NORMAL_TL
                );
                break;
            }
        }
    }
}

/**
 * Move the Droplet sprite in the desired direction.
 */
void MoveDroplet(UINT8 direction)
{
    switch (direction) {
        case J_LEFT: {
            if (!droplet_global.pressed)
            {
                switch (droplet_global.state) {
                    case DROPLET_STATE_NORMAL_RIGHT:
                    case DROPLET_STATE_SQUAT_RIGHT: {
                        FlipHorizontalSpriteSquare16(&droplet_global.sprite);
                        break;
                    }
                }
                ScrollSpriteSquare16(&droplet_global.sprite, -8, 0);
                droplet_global.pos.x -= 1;
                droplet_global.pressed = 1;
                droplet_global.state |= 1;  // Reverse direction
                droplet_global.state_counter = DROPLET_COUNTER_MAX;
            }
            break;
        }
        case J_RIGHT: {
            if (!droplet_global.pressed)
            {
                switch (droplet_global.state) {
                    case DROPLET_STATE_NORMAL_LEFT:
                    case DROPLET_STATE_SQUAT_LEFT: {
                        FlipHorizontalSpriteSquare16(&droplet_global.sprite);
                        break;
                    }
                }
                ScrollSpriteSquare16(&droplet_global.sprite, 8, 0);
                droplet_global.pos.x += 1;
                droplet_global.pressed = 1;
                droplet_global.state &= -2;  // Reverse direction
                droplet_global.state_counter = DROPLET_COUNTER_MAX;
            }
            break;
        }
        case J_UP: {
            if (!droplet_global.pressed)
            {
                ScrollSpriteSquare16(&droplet_global.sprite, 0, -8);
                droplet_global.pos.y -= 1;
                droplet_global.pressed = 1;
                droplet_global.state_counter = DROPLET_COUNTER_MAX;
            }
            break;
        }
        case J_DOWN: {
            if (!droplet_global.pressed)
            {
                ScrollSpriteSquare16(&droplet_global.sprite, 0, 8);
                droplet_global.pos.y += 1;
                droplet_global.pressed = 1;
                droplet_global.state_counter = DROPLET_COUNTER_MAX;
            }
            break;
        }
        default: {
            droplet_global.pressed = 0;
            break;
        }
    }
}
