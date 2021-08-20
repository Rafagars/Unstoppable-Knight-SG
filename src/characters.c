#include "characters.h"

u8 i;
bool hit = FALSE;
bool shield = FALSE;
u8 hitTimer = 30;
u8 shieldTimer = 15;
Sprite* shield_sprite;

bool checkCollision(Entity* one, Entity* two){
    return((one->x >= two->x && one->x <= two->x + two->w) && (one->y >= two->y && one->y <= two->y + two->h)) || ((two->x >= one->x && two->x <= one->x + one->w) && (two->y >= one->y && two->y <= one->y + one->h));
}

// Gives the player a smaller hitbox
bool checkPlayerCollision(Entity* character){
    return((player.x  + 4 >= character->x && player.x + 4 <= character->x + character->w) && (player.y + 4 >= character->y && player.y + 4 <= character->y + character->h)) || ((character->x >= player.x + 4 && character->x <= player.x + player.w - 4) && (character->y >= player.y + 4 && character->y <= player.y + player.h - 4));
}

void killCharacter(Entity* en){
    en->health = 0;
    SPR_setVisibility(en->sprite, HIDDEN);
}

void reviveCharacter(Entity* en){
    en->health = 1;
    if(en->w < 32){
        en->x = LEFT_EDGE + 8 + 32*randomize(5);
    } else {
        en->x = LEFT_EDGE + 32*randomize(5);
    }
    en->y = 254;
    SPR_setVisibility(en->sprite, VISIBLE);
}

void setupCoins(){
    Entity* c = coins;
    for(i = 0; i < 5; i++){
        c->x = LEFT_EDGE + 32*randomize(5);
        c->y = 224 + 16*i;
        c->w = 16;
        c->h = 16;
        c->health = 1;
        c->sprite = SPR_addSprite(&coin, c->x, c->y, TILE_ATTR(PAL2, 1, FALSE, FALSE));
        SPR_setAnim(c->sprite, 0);
        c++;
    }
}

void setupArrows(u8 x){
    arrows.x = LEFT_EDGE + x + 8;
    arrows.y = 255;
    arrows.w = 8;
    arrows.h = 16;
    arrows.health = 1;
    arrows.sprite = SPR_addSprite(&arrow, arrows.x, arrows.y, TILE_ATTR(PAL2, 0, FALSE, FALSE));
}

void setupOrcs(u8 x){
    orcs.x = LEFT_EDGE + x;
    orcs.y = 255;
    orcs.w = 32;
    orcs.h = 32;
    orcs.health = 1;
    orcs.sprite = SPR_addSprite(&orc, orcs.x, orcs.y, TILE_ATTR(PAL1, 0, FALSE, FALSE));
}

void setupPits(u8 x){
    pits.x = LEFT_EDGE + x;
    pits.y = 255;
    pits.w = 32;
    pits.h = 32;
    pits.health = 1;
    pits.sprite = SPR_addSprite(&pit, pits.x, pits.y, TILE_ATTR(PAL0, 0, FALSE, FALSE));
}

void setupBombs(u8 x){
    bombs.x = LEFT_EDGE + x + 8;
    bombs.y = 255;
    bombs.w = 16;
    bombs.h = 16;
    bombs.health = 1;
    bombs.sprite = SPR_addSprite(&bomb, bombs.x, bombs.y, TILE_ATTR(PAL3, 0, FALSE, FALSE));
}

void moveCoins(){
    Entity* c = coins;
    for(i = 0; i < 5; i++){
        c->y -= 1;
        if(c->y < 4){
            reviveCharacter(c);
        }
        if(checkCollision(c, &player)){
            killCharacter(c);
            c->y = 0;
            coins_counter++;
            score += 10;
            updateCoinsDisplay();
            updateScoreDisplay();
        }
        SPR_setPosition(c->sprite, c->x, c->y);
        c++;
    }
}

void moveEnemies(){
    Entity* obs[4] = {&arrows, &orcs, &pits, &bombs};

    arrows.y -= 3;
    orcs.y -= 2;
    pits.y -= 1;
    bombs.y -= 1;

    if(checkPlayerCollision(&arrows) && !hit){
        killCharacter(&arrows);
        arrows.y = 0;
        if(!shield){
            hit = TRUE;
            SPR_setAnim(player.sprite, ANIM_HIT);
            player.health--;
        }
    }

    if(checkPlayerCollision(&bombs) && !hit){
        killCharacter(&bombs);
        bombs.y = 0;
        if(!shield){
            hit = TRUE;
            SPR_setAnim(player.sprite, ANIM_HIT);
            player.health--;
        }
    }

    if((checkPlayerCollision(&orcs) || checkPlayerCollision(&pits)) && !hit){
        hit = TRUE;
        SPR_setAnim(player.sprite, ANIM_HIT);
        player.health--;
    }

    for(i = 0; i < 4; i++){
        SPR_setPosition(obs[i]->sprite, obs[i]->x, obs[i]->y);
        if(obs[i]->y < 4){
            reviveCharacter(obs[i]);
        }
    }

}