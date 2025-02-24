/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-03-08
 */

/* ===== Includes ===== */
#include "Hitbox.h"

/* ===== Functions ===== */

/**
 * Scroll hitbox in the given direction.
 */
void ScrollHitbox(Hitbox* hitbox_ptr, UINT8 speed_x, UINT8 speed_y)
{
    hitbox_ptr->tl.x += speed_x;
    hitbox_ptr->tl.y += speed_y;
    hitbox_ptr->br.x += speed_x;
    hitbox_ptr->br.y += speed_y;
}

