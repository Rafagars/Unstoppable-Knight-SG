#ifndef _CHARACTERS_H
#define _CHARACTERS_H

#include "functions.h"

#define ANIM_WALK 0
#define ANIM_HIT 1
#define MAX_ENEMIES 2

extern u8 i;
extern bool hit;
extern bool shield;
extern u8 hitTimer;
extern u8 shieldTimer;
extern Sprite* shield_sprite;

extern bool checkCollision(Entity* one, Entity* two);
extern bool checkPlayerCollision(Entity* character);
extern void killCharacter(Entity* en);
extern void reviveCharacter(Entity* en);
extern void setupCoins();
extern void setupArrows(u8 x);
extern void setupOrcs(u8 x);
extern void setupPits(u8 x);
extern void setupBombs(u8 x);
extern void moveEnemies();
extern void moveCoins();

#endif