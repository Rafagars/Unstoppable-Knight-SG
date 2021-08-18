#include "functions.h"

u8 i;
const int scrollsped = 2;
bool onTitle;

//Screen messages for the player
const char msg_start[22] = "Press START to begin";
const char msg_reset[22] = "GAME OVER\tPress START";
const char msg_pause[6] = "PAUSED";
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
        VDP_drawText(label_score, 1, 0);
        VDP_drawText(str_score, 1, 1);
        VDP_drawText(str_coins, 35, 1);
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
        game_on = FALSE;
    }
    score = 0;
}

void myJoyHandler(u16 joy, u16 changed, u16 state){
    if(joy == JOY_1){
        if(game_on == TRUE){
            if(state & BUTTON_LEFT){
                player.x -= 32;
            } else if(state & BUTTON_RIGHT){
                player.x += 32;
            }
            if(state & BUTTON_START){
                pauseGame();
            }
        } else {
            if(state & BUTTON_START){
                startGame();
                if(onTitle){
                    VDP_clearText(0, 23, 32);
                    level();   
                }
            }
        }
    }
}

u16 randomize(u16 n){
    return random() % n;
}