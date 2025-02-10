/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-04
 */

#ifndef DROPLET_SPRITE_TILE_INDEX_H
#define DROPLET_SPRITE_TILE_INDEX_H

/* ===== Data Types ===== */

/* Direction that the sprite is facing. */
typedef enum {
    SPRITE_DIR_UP    = 0,
    SPRITE_DIR_RIGHT = 1,
    SPRITE_DIR_DOWN  = 2,
    SPRITE_DIR_LEFT  = 3
} SpriteDirection;

/* Reference for sprite tile indices. */
typedef enum {

    /* The null sprite. */
    SPRITE_NULL = 0,

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
    SPRITE_DROPLET_16_SQUAT_L_BR,

    SPRITE_RAIN = 24,
    SPRITE_GATE = 25,

    /* Switches in various positions */
    SPRITE_SWITCH_DOWN_OFF = 26,
    SPRITE_SWITCH_DOWN_ON = 27,
    SPRITE_SWITCH_LEFT_OFF = 28,
    SPRITE_SWITCH_LEFT_ON = 29,
    SPRITE_SWITCH_UP_OFF = 30,
    SPRITE_SWITCH_UP_ON = 31,
    SPRITE_SWITCH_RIGHT_OFF = 32,
    SPRITE_SWITCH_RIGHT_ON = 33,

    /* Level Selector */
    SPRITE_LEVEL_SELECTOR_0 = 34,
    SPRITE_LEVEL_SELECTOR_1 = 35,
    SPRITE_LEVEL_SELECTOR_2 = 36,
    SPRITE_LEVEL_SELECTOR_3 = 37,
    SPRITE_LEVEL_SELECTOR_4 = 38,
    SPRITE_LEVEL_SELECTOR_5 = 39,

    /* Spider, 16x16, state 0  */
    SPRITE_SPIDER_16_STATE_0_TL  = 40,
    SPRITE_SPIDER_16_STATE_0_BL,
    SPRITE_SPIDER_16_STATE_0_TR,
    SPRITE_SPIDER_16_STATE_0_BR,

    /* Spider, 16x16, state 1  */
    SPRITE_SPIDER_16_STATE_1_TL  = 44,
    SPRITE_SPIDER_16_STATE_1_BL,
    SPRITE_SPIDER_16_STATE_1_TR,
    SPRITE_SPIDER_16_STATE_1_BR,

    /* The total number of sprites. */
    SPRITE_TILE_COUNT
} SpriteTileIndex;

#endif  /* DROPLET_SPRITE_TILE_INDEX_H */
