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
    VDP_clearText(0, 1, 6);
    VDP_drawText(str_score, 1, 1);
}

void updateCoinsDisplay(){
    if(coins_counter < 10){
        sprintf(str_coins, "X0%d", coins_counter);
    } else {
        sprintf(str_coins, "X%d", coins_counter);
    }
    VDP_clearText(35, 1, 3);
    VDP_drawText(str_coins, 35, 1);
}