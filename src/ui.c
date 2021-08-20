#include "ui.h"

Sprite* coin_counter_sprite;
Sprite* heart_ui;
u16 score = 0;
char label_score[6] = "SCORE\0";
char str_score[6] = "0";
u8 coins_counter = 0;
char str_coins[4] = "X00";

void updateScoreDisplay(){
    sprintf(str_score, "%d", score);
    VDP_clearText(17, 0, 5);
    VDP_drawText(str_score, 16, 0);
}

void updateCoinsDisplay(){
    if(coins_counter > 99){
        coins_counter = 0;
        if(player.health < 3){
            player.health++;
        }
    }
    if(coins_counter < 10){
        sprintf(str_coins, "X0%d", coins_counter);
    } else {
        sprintf(str_coins, "X%d", coins_counter);
    }
    VDP_clearText(35, 0, 3);
    VDP_drawText(str_coins, 22, 0);
}

void updateHealthDisplay(){
    switch (player.health) {
        case 3:
            SPR_setAnim(heart_ui, 0);
            break;
        case 2:
            SPR_setAnim(heart_ui, 1);
            break;
        case 1:
            SPR_setAnim(heart_ui, 2);
            break;
        case 0:
            SPR_setAnim(heart_ui, 3);
            endGame();
            break;
    }
}