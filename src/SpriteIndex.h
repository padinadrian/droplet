/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/04
 */

#ifndef DROPLET_SPRITE_INDEX_H
#define DROPLET_SPRITE_INDEX_H

/* ===== Data Types ===== */

/* Reference for sprite tile indices. */
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
    SPRITE_DROPLET_16_SQUAT_L_BR,

    /* The total number of sprites. */
    SPRITE_COUNT = 24
} SpriteIndex;


#endif  /* DROPLET_SPRITE_INDEX_H */
