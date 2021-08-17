#include "characters.h"

bool checkCollision(Entity* one, Entity* two){
    return((one->x >= two->x && one->x <= two->x + two->w) && (one->y >= two->y && one->y <= two->y + two->h)) || ((two->x >= one->x && two->x <= one->x + one->w) && (two->y >= one->y && two->y <= one->y + one->h));
}

void killCharacter(Entity* en){
    en->health = 0;
    SPR_setVisibility(en->sprite, HIDDEN);
}

void reviveCharacter(Entity* en){
    if(en->name == "KNIGHT"){
        en->health = 3;
    } else {
        en->health = 1;
    }
    SPR_setVisibility(en->sprite, VISIBLE);
}