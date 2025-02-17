/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-08
 */

#ifndef DROPLET_DROPLET_H
#define DROPLET_DROPLET_H

/* ===== Includes ===== */
#include "Position.h"
#include "SpriteSquare16.h"

/* ===== Data Types ===== */

// Data needed to manage Droplet.
typedef struct {
    SpriteSquare16 sprite;
    Position pos;
    UINT8 state;
    UINT8 state_counter;
    UINT8 pressed;
} Droplet;

// Reference to global Droplet instance.
extern Droplet droplet_global;

/* ===== Functions ===== */

/**
 * Initialize Droplet sprite and data.
 */
void DropletInitialize(Position start_pos);

/**
 * Animate Droplet squatting when he is idle.
 * This function should be called once per game loop.
 */
void DropletAnimate();

/**
 * Initialize Droplet sprite.
 */
void MoveDroplet(UINT8 direction);

#endif  /* DROPLET_DROPLET_H */
