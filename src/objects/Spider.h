/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2025-02-09
 */

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Position.h"
#include "SpriteSquare16.h"

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
    SPIDER_STATE0,
    SPIDER_STATE1,
    NUM_SPIDER_STATES,
} SpiderState;

/* ===== Functions ===== */

/**
 * Initialize Spider sprite and data.
 */
void SpiderInitialize(Spider* spider_ptr);

/**
 * Update the spider object including movement and animation.
 */
void UpdateSpider(Spider* spider_ptr);
