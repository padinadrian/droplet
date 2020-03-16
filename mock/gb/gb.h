
#ifndef DROPLET_MOCK_GB_H
#define DROPLET_MOCK_GB_H

typedef unsigned char UINT8;

typedef enum {
    J_LEFT,
    J_RIGHT,
    J_UP,
    J_DOWN,
} MOCK_JOYPAD_DIRECTION;

static inline void set_sprite_data(UINT8 a, UINT8 b, unsigned char c[]) {}
static inline void set_sprite_tile(UINT8 a, UINT8 b) {}
static inline void move_sprite(UINT8 a, UINT8 b, UINT8 c) {}
static inline void scroll_sprite(UINT8 a, UINT8 b, UINT8 c) {}
static inline void delay(int a) {}

#define SHOW_SPRITES (void)0

#endif  /* DROPLET_MOCK_GB_H */
