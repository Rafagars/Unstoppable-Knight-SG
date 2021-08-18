#ifndef _UI_H
#define _UI_H

#include "functions.h"

extern Sprite* coin_counter_sprite;
extern Sprite* heart_ui;

extern u16 score;
extern char label_score[6];
extern char str_score[6];
extern u8 coins_counter;
extern char str_coins[4];

extern void updateScoreDisplay();
extern void updateCoinsDisplay();
extern void updateHealthDisplay();

#endif