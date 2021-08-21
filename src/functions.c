#include "functions.h"

u8 i;
const int scrollsped = 2;
bool onTitle;
bool gameOver = FALSE;

//Screen messages for the player
const char msg_start[22] = "Press START to begin";
const char msg_reset[22] = "GAME OVER\tPress START";
const char msg_pause[7] = "PAUSED";
bool game_on = FALSE;

void showText(char s[]){
    VDP_drawText(s, 20 - strlen(s)/2, 12);
};

void clearText(){
    VDP_clearText(0, 12, 32);
}

void startGame(){
    if(game_on == FALSE){
        game_on = TRUE;
        clearText();
        VDP_drawText(label_score, 10, 0);
        VDP_drawText(str_score, 16, 0);
        VDP_drawText(str_coins, 22, 0);
        updateScoreDisplay();
        updateCoinsDisplay();
    }

}

void pauseGame(){
    if(game_on == TRUE){
        showText(msg_pause);
        game_on = FALSE;
    }
}

void endGame(){
    if(game_on == TRUE){
        showText(msg_reset);
        shield = FALSE;
        hit = FALSE;
        game_on = FALSE;
        gameOver = TRUE;
        reviveCharacter(&arrows);
        reviveCharacter(&orcs);
        reviveCharacter(&pits);
        reviveCharacter(&bombs);
    }
    score = 0;
    coins_counter = 0;
}

void myJoyHandler(u16 joy, u16 changed, u16 state){
    if(joy == JOY_1){
        if(game_on == TRUE){
            if(state & BUTTON_LEFT){
                player.x -= 32;
            } else if(state & BUTTON_RIGHT){
                player.x += 32;
            }
            if(state & BUTTON_B){
                shield = TRUE;
                SPR_setVisibility(shield_sprite, VISIBLE);
            }
            if(state & BUTTON_START){
                pauseGame();
            }
        } else {
            if(state & BUTTON_START){
                startGame();
                if(onTitle || gameOver){
                    VDP_clearText(0, 23, 32);
                    gameOver = FALSE;
                    level();
                }
            }
        }
    }
}

u16 randomize(u16 n){
    return random() % n;
}