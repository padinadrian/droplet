/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2025-02-23
 */

 #ifndef DROPLET_HITBOX_H
 #define DROPLET_HITBOX_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Position.h"

/* ===== Data Types ===== */

/** Represents a rectangular hitbox. */
typedef struct {
    Position tl;    // Top-left corner
    Position br;    // Bottom-right corner
} Hitbox;

/* ===== Functions ===== */

/**
 * Check if two hitboxes overlap.
 */
static inline UINT8 CheckCollision(Hitbox* a, Hitbox* b)
{
    return (
        a->tl.x < b->br.x &&
        a->br.x > b->tl.x &&
        a->tl.y < b->br.y &&
        a->br.y > b->tl.y
    );
}

/**
 * Check collision between a hitbox and a point.
 */
static inline UINT8 CheckCollisionPoint(Hitbox* a, Position* b)
{
    return (
        a->tl.x < b->x && a->br.x > b->x &&
        a->tl.y < b->y && a->br.y > b->y
    );
}

/**
 * Scroll hitbox in the given direction.
 */
void ScrollHitbox(Hitbox* hitbox_ptr, UINT8 speed_x, UINT8 speed_y);


#endif  /* DROPLET_HITBOX_H */
