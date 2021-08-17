#include <genesis.h>
#include "functions.h"

int main(){
    //Input
    JOY_init();
    JOY_setEventHandler(&myJoyHandler);

    // Disable interrupts
    SYS_disableInts();

    titleScreen();

    SPR_init(0, 0, 0);
    player.sprite = SPR_addSprite(&knight, player.x, player.y, TILE_ATTR(PAL0, 1, FALSE, FALSE));
    killCharacter(&player);

    // VDP process done, we can re enable interrupts
    SYS_enableInts();

    // Plane scroll
    VDP_setScrollingMode(HSCROLL_PLANE, VSCROLL_PLANE);

    u8 offset = 0;
    while(1){
        VDP_setVerticalScroll(BG_B, offset += 1);
        if(game_on){
            if(player.x < LEFT_EDGE){
                player.x = LEFT_EDGE;
            } else if(player.x > RIGHT_EDGE){
                player.x = 208;
            }
            SPR_setPosition(player.sprite, player.x, player.y);
            SPR_update();
        }
        SYS_doVBlankProcess();
    }
    return 0;
}