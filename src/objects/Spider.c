/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2025-02-09
 */

/* ===== Includes ===== */
#include "Debug.h"
#include "Droplet.h"
#include "Spider.h"
#include "Sprites.h"
#include "SpriteTileIndex.h"
#include "Utility.h"

/* ===== Data Types ===== */

/** The animation states of the Spider. */
typedef enum {
    SPIDER_STATE_0,
    SPIDER_STATE_1,
    NUM_SPIDER_STATES,
} SpiderState;

enum { SPIDER_MAX_COUNTER = 15 };

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

    // Initialize hitbox
    UINT8 hitbox_tl_x = spider_ptr->pos.x << 3;
    UINT8 hitbox_tl_y = spider_ptr->pos.y << 3;
    spider_ptr->hitbox.tl.x = hitbox_tl_x;
    spider_ptr->hitbox.tl.y = hitbox_tl_y;
    spider_ptr->hitbox.br.x = hitbox_tl_x + 15;
    spider_ptr->hitbox.br.y = hitbox_tl_y + 15;
}

/**
 * Update the spider object including movement and animation.
 */
void UpdateSpider(Spider* spider_ptr)
{
    // Update state counter
    UINT8 counter = IncrementRollover(spider_ptr->state_counter, SPIDER_MAX_COUNTER);
    spider_ptr->state_counter = counter;

    // Move the spider
    if ((counter & 1) == 0) {
        INT8 speed = spider_ptr->direction ? 1 : -1;
        ScrollSpriteSquare16(&spider_ptr->sprite, speed, 0);

        spider_ptr->hitbox.tl.x += speed;
        spider_ptr->hitbox.br.x += speed;

        // Check wall collision
        UINT8 hitbox_x = 0, hitbox_y = 0;
        Hitbox wall_hitbox;
        for (UINT8 i = 0; i < spider_ptr->num_walls; ++i) {
            hitbox_x = spider_ptr->walls[i].x << 3;
            hitbox_y = spider_ptr->walls[i].y << 3;
            wall_hitbox.tl.x = hitbox_x;
            wall_hitbox.tl.y = hitbox_y;
            wall_hitbox.br.x = hitbox_x + 7;
            wall_hitbox.br.y = hitbox_y + 7;

            if (CheckCollision(&wall_hitbox, &spider_ptr->hitbox) ) {
                spider_ptr->direction ^= 1;
            }
        }
    }

    // Animate the spider
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


