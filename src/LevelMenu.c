/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

/* ===== Includes ===== */
#include "LevelMenu.h"
#include "Levels.h"

/* ===== Functions ===== */

/**
 * Display level-picking menu.
 */
void LevelMenu()
{
    UINT8 level_number = 1;
    PlayLevel(level_number);
}
