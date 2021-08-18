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
extern Entity coins[6];
extern Entity arrows;
extern Entity orcs;
extern Entity pits;
extern Entity bombs;

#endif