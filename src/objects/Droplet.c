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

// The animation states of the Spider.
typedef enum {
    DROPLET_STATE_NORMAL_RIGHT,
    DROPLET_STATE_NORMAL_LEFT,
    DROPLET_STATE_SQUAT_RIGHT,
    DROPLET_STATE_SQUAT_LEFT,
    NUM_DROPLET_STATES,
} DropletState;

enum { DROPLET_COUNTER_MAX = 20 };

/* ===== Functions ===== */

/**
 * Initialize Droplet sprite and data.
 */
void DropletInitialize(Droplet* droplet_ptr, Position* start_pos)
{
    /* Reset status flags and counters. */
    droplet_ptr->state = DROPLET_STATE_NORMAL_RIGHT;
    droplet_ptr->state_counter = 0;
    droplet_ptr->pressed = 0;

    /* Set sprite IDs. */
    SpriteSquare16* sprite_ptr = &(droplet_ptr->sprite);
    InitializeSpriteSquare16(sprite_ptr);

    /* Droplet starts off in normal position facing right. */
    SetSpriteTileSquare16(
        sprite_ptr,
        (UINT8)SPRITE_DROPLET_16_NORMAL_TL
    );

    PositionCopy(&droplet_ptr->pos, start_pos);
}

/**
 * Animate Droplet squatting when he is idle.
 * This function should be called once per game loop.
 */
void DropletAnimate(Droplet* droplet_ptr)
{
    // Update state counter
    UINT8 counter = IncrementRollover(droplet_ptr->state_counter, DROPLET_COUNTER_MAX);
    droplet_ptr->state_counter = counter;

    if (counter == 0) {
        switch (droplet_ptr->state) {
            // Normal state
            case DROPLET_STATE_NORMAL_RIGHT: {
                droplet_ptr->state = DROPLET_STATE_SQUAT_RIGHT;
                SetSpriteTileSquare16(
                    &droplet_ptr->sprite,
                    (UINT8)SPRITE_DROPLET_16_SQUAT_TL
                );
                break;
            }
            case DROPLET_STATE_NORMAL_LEFT: {
                droplet_ptr->state = DROPLET_STATE_SQUAT_LEFT;
                SetSpriteTileSquare16(
                    &droplet_ptr->sprite,
                    (UINT8)SPRITE_DROPLET_16_SQUAT_TL
                );
                break;
            }
            // Squatting state
            case DROPLET_STATE_SQUAT_RIGHT:{
                droplet_ptr->state = DROPLET_STATE_NORMAL_RIGHT;
                SetSpriteTileSquare16(
                    &droplet_ptr->sprite,
                    (UINT8)SPRITE_DROPLET_16_NORMAL_TL
                );
                break;
            }
            case DROPLET_STATE_SQUAT_LEFT: {
                droplet_ptr->state = DROPLET_STATE_NORMAL_LEFT;
                SetSpriteTileSquare16(
                    &droplet_ptr->sprite,
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
void MoveDroplet(
        Droplet* droplet_ptr,
        UINT8 direction)
{
    switch (direction) {
        case J_LEFT: {
            if (!droplet_ptr->pressed)
            {
                switch (droplet_ptr->state) {
                    case DROPLET_STATE_NORMAL_RIGHT:
                    case DROPLET_STATE_SQUAT_RIGHT: {
                        droplet_ptr->state = DROPLET_STATE_NORMAL_LEFT;
                        FlipHorizontalSpriteSquare16(&droplet_ptr->sprite);
                        break;
                    }
                }
                ScrollSpriteSquare16(&droplet_ptr->sprite, -8, 0);
                droplet_ptr->pos.x -= 1;
                droplet_ptr->pressed = 1;
            }
            droplet_ptr->state_counter = DROPLET_COUNTER_MAX;
            break;
        }
        case J_RIGHT: {
            if (!droplet_ptr->pressed)
            {
                switch (droplet_ptr->state) {
                    case DROPLET_STATE_NORMAL_LEFT:
                    case DROPLET_STATE_SQUAT_LEFT: {
                        droplet_ptr->state = DROPLET_STATE_NORMAL_RIGHT;
                        FlipHorizontalSpriteSquare16(&droplet_ptr->sprite);
                        break;
                    }
                }
                ScrollSpriteSquare16(&droplet_ptr->sprite, 8, 0);
                droplet_ptr->pos.x += 1;
                droplet_ptr->pressed = 1;
            }
            droplet_ptr->state_counter = DROPLET_COUNTER_MAX;
            break;
        }
        case J_UP: {
            if (!droplet_ptr->pressed)
            {
                ScrollSpriteSquare16(&droplet_ptr->sprite, 0, -8);
                droplet_ptr->pos.y -= 1;
                droplet_ptr->pressed = 1;
            }
            droplet_ptr->state_counter = DROPLET_COUNTER_MAX;
            break;
        }
        case J_DOWN: {
            if (!droplet_ptr->pressed)
            {
                ScrollSpriteSquare16(&droplet_ptr->sprite, 0, 8);
                droplet_ptr->pos.y += 1;
                droplet_ptr->pressed = 1;
            }
            droplet_ptr->state_counter = DROPLET_COUNTER_MAX;
            break;
        }
        default: {
            droplet_ptr->pressed = 0;
            break;
        }
    }
}
