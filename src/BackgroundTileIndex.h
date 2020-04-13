/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/04
 */

#ifndef DROPLET_BACKGROUND_TILE_INDEX_H
#define DROPLET_BACKGROUND_TILE_INDEX_H

/* ===== Data Types ===== */

/* Reference for sprite tile indices. */
typedef enum {
    /* Droplet, 16x16, normal, facing right  */
    BG_TILE_EXTERIOR_WALL_TL = 4,
    BG_TILE_EXTERIOR_WALL_TR = 5,
    BG_TILE_EXTERIOR_WALL_BL = 6,
    BG_TILE_EXTERIOR_WALL_BR = 7,

    /* The total number of sprites. */
    BG_TILE_COUNT = 24

} BackgroundTileIndex;


#endif  /* DROPLET_BACKGROUND_TILE_INDEX_H */
