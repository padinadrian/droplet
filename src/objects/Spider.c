/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2025-02-09
 */

/* ===== Includes ===== */
#include "Debug.h"
#include "Droplet.h"
#include "Sprites.h"
#include "SpriteTileIndex.h"
#include "Utility.h"

/* ===== Data Types ===== */

// Data needed for a Spider object.
typedef struct {
    SpriteSquare16 sprite;
    Position pos;
    UINT8 state;
    UINT8 state_counter;
} Spider;

// The animation states of the Spider.
typedef enum {
    SPIDER_STATE_0,
    SPIDER_STATE_1,
    NUM_SPIDER_STATES,
} SpiderState;

enum { SPIDER_MAX_COUNTER = 8 };

/* ===== Functions ===== */

/**
 * Initialize Spider sprite and data.
 */
void SpiderInitialize(Spider* spider_ptr)
{
    // Initial state
    spider_ptr->state = SPIDER_STATE_0;
    spider_ptr->state_counter = 0;

    // Initialize sprites
    SpriteSquare16* sprite_ptr = &(spider_ptr->sprite);
    InitializeSpriteSquare16(sprite_ptr);

    SetSpriteTileSquare16(
        sprite_ptr,
        (UINT8)SPRITE_SPIDER_16_STATE_0_TL
    );
    MoveSpriteSquare16(
        sprite_ptr,
        spider_ptr->pos.x << 3,
        spider_ptr->pos.y << 3
    );
}

/**
 * Update the spider object including movement and animation.
 */
void UpdateSpider(Spider* spider_ptr)
{
    // Update state counter
    UINT8 counter = IncrementRollover(spider_ptr->state_counter, SPIDER_MAX_COUNTER);
    spider_ptr->state_counter = counter;

    if (counter == 0) {
        SpiderState new_state = IncrementRollover(spider_ptr->state, NUM_SPIDER_STATES - 1);
        spider_ptr->state = new_state;

        switch (new_state) {
            case SPIDER_STATE_0: {
                SetSpriteTileSquare16(
                    &spider_ptr->sprite,
                    (UINT8)SPRITE_SPIDER_16_STATE_0_TL
                );
                break;
            }
            case SPIDER_STATE_1: {
                SetSpriteTileSquare16(
                    &spider_ptr->sprite,
                    (UINT8)SPRITE_SPIDER_16_STATE_1_TL
                );
                break;
            }
        }
    }
}


