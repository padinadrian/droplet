/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/06/01
 */

#ifndef DROPLET_UTILITY_H
#define DROPLET_UTILITY_H

/* ===== Includes ===== */
#include <gb/gb.h>

/* ===== Functions ===== */

/**
 * Returns a bitmask with only the changed buttons set.
 * Effectively calculates the rising edge of the button presses.
 */
UINT8 JoypadChanges(UINT8 input);

/**
 * Increment the counter, rolling over to 0 if the counter reaches max.
 */
static inline UINT8 IncrememntRollover(UINT8 counter, UINT8 max) {
    return (counter < max) ? counter + 1 : 0;
}

#endif  /* DROPLET_UTILITY_H */
