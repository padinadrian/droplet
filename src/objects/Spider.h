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

/** Defines a wall object to bound the Spider's movement area. */
typedef struct {
    UINT8 x: 4;
    UINT8 y: 4;
} Wall;

/** Defines a Spider enemy. */
typedef struct {
    SpriteSquare16 sprite;
    Position pos;
    Hitbox hitbox;
    UINT8 state;
    UINT8 state_counter;
    Wall walls[4];
    UINT8 num_walls;
    UINT8 direction;
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
