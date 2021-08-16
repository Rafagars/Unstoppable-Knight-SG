#ifndef _CHARACTERS_H
#define _CHARACTERS_H

#include "functions.h"

extern void moveEnemies();
extern void positionEnemies();
extern bool checkCollision(Entity* one, Entity* two);
extern void handleCollision(Entity* en);
extern void killCharacter(Entity* en);
extern void reviveCharacter();

#endif