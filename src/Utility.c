/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020-06-01
 */

/* ===== Includes ===== */
#include  "Utility.h"

/* ===== Functions ===== */

/** Returns a bitmask with only the changed buttons set. */
UINT8 JoypadChanges(UINT8 input)
{
    static UINT8 state = 0;
    UINT8 changes = input & ~state;
    state = input;
    return changes;
}
