#ifndef _CHARACTERS_H
#define _CHARACTERS_H

#include "functions.h"

#define ANIM_WALK 0
#define MAX_ENEMIES 2

extern bool checkCollision(Entity* one, Entity* two);
extern void handleCollision(Entity* en);
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