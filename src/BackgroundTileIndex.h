/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/04
 */

#ifndef DROPLET_BACKGROUND_TILE_INDEX_H
#define DROPLET_BACKGROUND_TILE_INDEX_H

/* ===== Data Types ===== */

/* Reference for sprite tile indices. */
typedef enum {
    BG_TILE_NULL = 0,

    /* Droplet, 16x16, normal, facing right  */
    BG_TILE_EXTERIOR_WALL_TL = 4,
    BG_TILE_EXTERIOR_WALL_TR,
    BG_TILE_EXTERIOR_WALL_BL,
    BG_TILE_EXTERIOR_WALL_BR,

    /* Droplet, 16x16, normal, facing right  */
    BG_TILE_STAIRCASE_TL = 20,
    BG_TILE_STAIRCASE_BL,
    BG_TILE_STAIRCASE_TR,
    BG_TILE_STAIRCASE_BR,

    /* The total number of sprites. */
    BG_TILE_COUNT = 29

} BackgroundTileIndex;


#endif  /* DROPLET_BACKGROUND_TILE_INDEX_H */
