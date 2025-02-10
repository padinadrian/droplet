/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-04
 */

#ifndef DROPLET_BACKGROUND_TILE_INDEX_H
#define DROPLET_BACKGROUND_TILE_INDEX_H

/* ===== Data Types ===== */

/* Background-related constants */
enum { NUM_SPLASH_TILES = 86 };
enum { NUM_LEVEL_MENU_TILES = 58 };
enum { NUM_BACKGROUND_TILES = 29 };
enum { BACKGROUND_TILE_START = 0x80 };

/* Reference for background tile indices. */
typedef enum {
    BG_TILE_NULL = 0 + BACKGROUND_TILE_START,

    /* Tile for staircase image.  */
    BG_TILE_STAIRCASE_TL = 17 + BACKGROUND_TILE_START,
    BG_TILE_STAIRCASE_BL,
    BG_TILE_STAIRCASE_TR,
    BG_TILE_STAIRCASE_BR

} BackgroundTileIndex;


#endif  /* DROPLET_BACKGROUND_TILE_INDEX_H */
