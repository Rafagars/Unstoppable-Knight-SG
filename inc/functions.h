#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <genesis.h>
#include <maths.h>
#include <resources.h>
#include <string.h>
#include "scenes.h"
#include "entity.h"
#include "characters.h"
#include "ui.h"

#define LEFT_EDGE 80
#define RIGHT_EDGE 224

#define SFX_PICK_UP 64
#define SFX_HIT 65
#define SFX_EXPLOSION 66

extern u8 i;
extern u8 scrollspeed;
extern bool onTitle;
extern bool gameOver;

extern const char msg_start[22];
extern const char msg_reset[22];
extern const char msg_pause[7];
extern bool game_on;

extern void showText(char s[]);
extern void clearText();

extern void startGame();
extern void pauseGame();
extern void endGame();

extern void myJoyHandler(u16 joy, u16 changed, u16 state);

extern u16 randomize(u16 n);

#endif