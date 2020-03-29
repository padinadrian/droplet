#include <stdio.h>
#include "Droplet.h"
#include "DropletMap.h"
#include "data/maps/droplet_level1_bg.c"

int main()
{
    DropletMap level1_map;
    Position droplet_grid_pos;
    Position droplet_pixel_pos;
    UINT8 joypad_input = 0;
    int index = 0;
    int x;
    int y;

    level1_map.map_data = DropletBackgroundLevel1;
    level1_map.width = DropletBackgroundLevel1Width;
    level1_map.height = DropletBackgroundLevel1Height;

    droplet_grid_pos.x = x = 2;
    droplet_grid_pos.y = y = 12;

    index = (level1_map.width * (int)10) + 1;
    printf(
        "map index: %d\n",
        index
    );
    index = (level1_map.width * (int)17) + 19;
    printf(
        "map index: %d\n",
        index
    );
    printf(
        "TileIsWall(1, 10): %x\n",
        TileIsWall(&level1_map, 1, 10)
    );
    printf(
        "TileIsWall(19, 10): %x\n",
        TileIsWall(&level1_map, 19, 10)
    );
    GridPosToPixelPos(&droplet_grid_pos);
    printf(
        "GridPosToPixelPos(2, 12): %d, %d\n",
        droplet_grid_pos.x,
        droplet_grid_pos.y
    );


    droplet_grid_pos.x = 1;
    droplet_grid_pos.y = 10;
    printf(
        "right: %d\n",
        DropletCheckMovement(
            J_RIGHT,
            &droplet_grid_pos,
            &level1_map
        )
    );
    printf(
        "left: %d\n",
        DropletCheckMovement(
            J_LEFT,
            &droplet_grid_pos,
            &level1_map
        )
    );
    printf(
        "up: %d\n",
        DropletCheckMovement(
            J_UP,
            &droplet_grid_pos,
            &level1_map
        )
    );
    printf(
        "down: %d\n",
        DropletCheckMovement(
            J_DOWN,
            &droplet_grid_pos,
            &level1_map
        )
    );
    droplet_grid_pos.x = 13;
    droplet_grid_pos.y = 10;
    printf(
        "right: %d\n",
        DropletCheckMovement(
            J_RIGHT,
            &droplet_grid_pos,
            &level1_map
        )
    );
    printf(
        "left: %d\n",
        DropletCheckMovement(
            J_LEFT,
            &droplet_grid_pos,
            &level1_map
        )
    );
    printf(
        "up: %d\n",
        DropletCheckMovement(
            J_UP,
            &droplet_grid_pos,
            &level1_map
        )
    );
    printf(
        "down: %d\n",
        DropletCheckMovement(
            J_DOWN,
            &droplet_grid_pos,
            &level1_map
        )
    );
}