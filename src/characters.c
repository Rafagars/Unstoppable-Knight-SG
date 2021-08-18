#include "characters.h"

u8 i;

bool checkCollision(Entity* one, Entity* two){
    return((one->x >= two->x && one->x <= two->x + two->w) && (one->y >= two->y && one->y <= two->y + two->h)) || ((two->x >= one->x && two->x <= one->x + one->w) && (two->y >= one->y && two->y <= one->y + one->h));
}

void killCharacter(Entity* en){
    en->health = 0;
    SPR_setVisibility(en->sprite, HIDDEN);
}

void reviveCharacter(Entity* en){
    en->health = 1;
    SPR_setVisibility(en->sprite, VISIBLE);
}

void setupCoins(){
    Entity* c = coins;
    for(i = 0; i < 8; i++){
        c->x = LEFT_EDGE + 32*randomize(6);
        c->y = 255;
        c->w = 16;
        c->h = 16;
        c->health = 1;
        c->sprite = SPR_addSprite(&coin, c->x, c->y, TILE_ATTR(PAL2, 1, FALSE, FALSE));
        SPR_setAnim(c->sprite, 0);
        c++;
    }
}
Entity* a = arrows;
void setupArrows(u8 x){
    a->x = LEFT_EDGE + x;
    a->y = 255;
    a->w = 8;
    a->h = 16;
    a->health = 1;
    a->sprite = SPR_addSprite(&arrow, a->x, a->y, TILE_ATTR(PAL2, 0, FALSE, FALSE));
    a++;
}
Entity* o = orcs;
void setupOrcs(u8 x){
    o->x = LEFT_EDGE + x;
    o->y = 255;
    o->w = 32;
    o->h = 32;
    o->health = 1;
    o->sprite = SPR_addSprite(&orc, o->x, o->y, TILE_ATTR(PAL1, 0, FALSE, FALSE));
    o++;
}
Entity* p = pits;
void setupPits(u8 x){
    p->x = LEFT_EDGE + x;
    p->y = 255;
    p->w = 32;
    p->h = 32;
    p->health = 1;
    p->sprite = SPR_addSprite(&pit, p->x, p->y, TILE_ATTR(PAL0, 0, FALSE, FALSE));
    p++;
}
Entity* b = bombs;
void setupBombs(u8 x){
    b->x = LEFT_EDGE + x;
    b->y = 255;
    b->w = 16;
    b->h = 16;
    b->health = 1;
    b->sprite = SPR_addSprite(&bomb, b->x, b->y, TILE_ATTR(PAL3, 0, FALSE, FALSE));
    b++;
}

void moveCoins(){
    Entity* c = coins;
    for(i = 0; i < 8; i++){
        c->y -= 1;
        if(c->y < 4){
            c->x = LEFT_EDGE + 32*randomize(5);
            c->y = 255;
        }
        if(checkCollision(c, &player)){
            coins_counter++;
            score += 10;
            updateCoinsDisplay();
            updateScoreDisplay();
        }
        c++;
    }
}

void moveEnemies(){
    Entity* a = arrows;
    Entity* o = orcs;
    Entity* p = pits;
    Entity* b = bombs;
    for(i = 0; i < MAX_ENEMIES; i++){
        a->y -= 3;
        o->y -= 2;
        p->y -= 1;
        b->y -= 1;
        SPR_setPosition(a->sprite, a->x, a->y);
        SPR_setPosition(o->sprite, o->x, o->y);
        SPR_setPosition(p->sprite, p->x, p->y);
        SPR_setPosition(b->sprite, b->x, b->y);

        if(a->y < 4){
            a->x = LEFT_EDGE + 32*randomize(5);
            a->y = 255;
        }
        if(o->y < 4){
            o->x = LEFT_EDGE + 32*randomize(5);
            o->y = 255;
        }
        if(p->y < 4){
            p->x = LEFT_EDGE + 32*randomize(5);
            p->y = 255;
        }
        if(b->y < 4){
            b->x = LEFT_EDGE + 32*randomize(5);
            b->y = 255;
        }
        a++;
        o++;
        p++;
        b++;
    }

}