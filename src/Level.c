/**
 *  Author: Adrian Padin (padin.adrian@gmail.com)
 *  Date:   2020/03/15
 */

/* ===== Includes ===== */
#include "Level.h"
#include "BackgroundTileIndex.h"
#include "data/tiles/droplet_background_tiles.h"
// #include "data/maps/droplet_level1_bg.h"

/* ===== Functions ===== */

/** Set the level map data. */
void SetLevelBackground(
    Level* level_ptr,
    UINT8* map_data,
    UINT8 map_width,
    UINT8 map_height
)
{
    level_ptr->level_map.map_data = map_data;
    level_ptr->level_map.width = map_width;
    level_ptr->level_map.height = map_height;
}

/** Load the level. */
void LoadLevel(
    Level* level_ptr,
    Droplet* droplet_ptr
)
{
    Position droplet_pixel_pos;

    set_bkg_data(0, BG_TILE_COUNT, DropletBkgTiles);
    SetBackground(&(level_ptr->level_map));
    DropletInitialize(droplet_ptr);

    droplet_pixel_pos.x = droplet_ptr->pos.x;
    droplet_pixel_pos.y = droplet_ptr->pos.y;
    GridPosToPixelPos(&droplet_pixel_pos);
    MoveSpriteSquare16(
        &(droplet_ptr->sprite),
        droplet_pixel_pos.x,
        droplet_pixel_pos.y
    );

    SHOW_SPRITES;
    SHOW_BKG;
}

/** Check if Droplet has reached the end of the level. */
UINT8 IsLevelComplete(
    Level* level_ptr,
    Position* droplet_pos_ptr
)
{
    droplet_pos_ptr->x == level_ptr->exit_pos.x;
    droplet_pos_ptr->y == level_ptr->exit_pos.y;
}
