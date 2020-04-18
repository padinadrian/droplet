/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/04/13
 */

/* ===== Includes ===== */
#include "SpriteCounter.h"

/* ===== Functions ===== */

/** Returns a semi-unique sprite ID. */
UINT8 GetSpriteID()
{
    static UINT8 sprite_counter = 0;
    return sprite_counter++;
}
