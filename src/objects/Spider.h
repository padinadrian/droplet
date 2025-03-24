/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2025-02-09
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Hitbox.h"
#include "Position.h"
#include "SpriteSquare16.h"

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

/** Define the Spider's current state. */
typedef struct {
    UINT8 anim_state: 2;
    UINT8 direction: 2;
} SpiderState;

/** Defines a Spider enemy. */
typedef struct {
    SpriteSquare16 sprite;
    Position pos;
    Hitbox hitbox;
    SpiderState state;
    UINT8 state_counter;
    Position walls[4];
    UINT8 num_walls;
} Spider;

/* ===== Functions ===== */

/**
 * Initialize Spider sprite and data.
 */
void SpiderInitialize(Spider* spider_ptr);

/**
 * Update the spider object including movement and animation.
 */
void UpdateSpider(Spider* spider_ptr);
