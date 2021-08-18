#ifndef _ENTITY_H
#define _ENTITY_H

#include <genesis.h>

typedef struct {
    s16 x;
    s16 y;
    u16 vel_x;
    u16 vel_y;
    u8 w;
    u8 h;
    u8 health;
    bool flip;
    Sprite* sprite;
    char name[8];
} Entity;

extern Entity player;
extern Entity coins[8];
extern Entity arrows[2];
extern Entity orcs[2];
extern Entity pits[2];
extern Entity bombs[2];

#endif