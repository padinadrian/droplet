/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

#ifndef DROPLET_LEVEL_MENU_H
#define DROPLET_LEVEL_MENU_H

/* ===== Includes ===== */
#include <gb/gb.h>
#include "Level.h"

/**
 * Enter the menu to select which level to play.
 */
void LevelMenu();

/**
 * Main game loop which runs the given level.
 */
void PlayLevel(Level* level_ptr);

#endif  /* DROPLET_LEVEL_MENU_H */
