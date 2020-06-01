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

#endif  /* DROPLET_UTILITY_H */
