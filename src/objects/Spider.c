/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2025-02-09
 */

/* ===== Includes ===== */
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
} SpiderAnimation;

/** Spider movement direction. */
typedef enum {
    DIRECTION_LEFT = 0,
    DIRECTION_DOWN = 1,
    DIRECTION_RIGHT = 2,
    DIRECTION_UP = 3,
    NUM_DIRECTIONS,
} SpiderDirection;

enum { SPIDER_MAX_COUNTER = 15 };

/* ===== Functions ===== */

/**
 * Initialize Spider sprite and data.
 */
void SpiderInitialize(Spider* spider_ptr)
{
    // Initial state
    spider_ptr->state.anim_state = SPIDER_STATE_0;
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
    // Hitbox is only 14x14 pixels
    UINT8 hitbox_tl_x = (spider_ptr->pos.x << 3) + 1;
    UINT8 hitbox_tl_y = (spider_ptr->pos.y << 3) + 1;
    spider_ptr->hitbox.tl.x = hitbox_tl_x;
    spider_ptr->hitbox.tl.y = hitbox_tl_y;
    spider_ptr->hitbox.br.x = hitbox_tl_x + 13;
    spider_ptr->hitbox.br.y = hitbox_tl_y + 13;
}

/**
 * Update the spider object including movement and animation.
 */
void UpdateSpider(Spider* spider_ptr)
{
    // Update state counter
    UINT8 counter = IncrementRollover(spider_ptr->state_counter, SPIDER_MAX_COUNTER);
    spider_ptr->state_counter = counter;

    // Move the spider (every even frame)
    if ((counter & 1) == 0) {
        INT8 speed_x = 0, speed_y = 0;
        switch (spider_ptr->state.direction) {
            case DIRECTION_LEFT:  speed_x = -1; break;
            case DIRECTION_DOWN:  speed_y =  1; break;
            case DIRECTION_RIGHT: speed_x =  1; break;
            case DIRECTION_UP:    speed_y = -1; break;
        }

        ScrollSpriteSquare16(&spider_ptr->sprite, speed_x, speed_y);
        spider_ptr->hitbox.tl.x += speed_x;
        spider_ptr->hitbox.tl.y += speed_y;
        spider_ptr->hitbox.br.x += speed_x;
        spider_ptr->hitbox.br.y += speed_y;

        // Check Droplet collision
        // TODO

        // Check wall collision
        UINT8 hitbox_x = 0, hitbox_y = 0;
        Hitbox wall_hitbox;
        for (UINT8 i = 0; i < spider_ptr->num_walls; ++i) {
            hitbox_x = (spider_ptr->walls[i].x << 3);
            hitbox_y = (spider_ptr->walls[i].y << 3);
            wall_hitbox.tl.x = hitbox_x - 2;
            wall_hitbox.tl.y = hitbox_y - 2;
            wall_hitbox.br.x = hitbox_x + 9;
            wall_hitbox.br.y = hitbox_y + 9;

            UINT8 collision = CheckCollision(&wall_hitbox, &spider_ptr->hitbox);
            if (collision) {
                // Move backwards
                ScrollSpriteSquare16(&spider_ptr->sprite, -speed_x, -speed_y);
                ScrollHitbox(&spider_ptr->hitbox, -speed_x, -speed_y);

                // Turn left
                UINT8 direction = spider_ptr->state.direction;
                direction = IncrementRollover(direction, NUM_DIRECTIONS);
                spider_ptr->state.direction = direction;
            }
        }
    }

    // Animate the spider
    if (counter == 0) {
        SpiderAnimation anim_state = spider_ptr->state.anim_state;
        anim_state = IncrementRollover(anim_state, NUM_SPIDER_STATES - 1);
        spider_ptr->state.anim_state = anim_state;

        switch (anim_state) {
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


