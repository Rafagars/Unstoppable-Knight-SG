#include <genesis.h>
#include "functions.h"

int main(){
    //Input
    JOY_init();
    JOY_setEventHandler(&myJoyHandler);

    // Set up palletes
    VDP_setPalette(PAL0, title.palette->data);
    VDP_setPalette(PAL1, bg_B.palette->data);
    VDP_setPalette(PAL2, ui.palette->data);
    VDP_setPalette(PAL3, bomb.palette->data);

    // Disable interrupts
    SYS_disableInts();

    //Title Screen scene
    titleScreen();
    
    //Set up player, coins and obstacles
    SPR_init(0, 0, 0);
    shield_sprite = SPR_addSprite(&shieldS, player.x, player.y + 16, TILE_ATTR(PAL0, 0, FALSE, FALSE));
    player.sprite = SPR_addSprite(&knight, player.x, player.y, TILE_ATTR(PAL0, 1, FALSE, FALSE));
    SPR_setVisibility(shield_sprite, HIDDEN);
    setupCoins();

    setupArrows(32*randomize(5));
    setupOrcs(32*randomize(5));
    setupPits(32*randomize(5));
    setupBombs(32*randomize(5));

    // VDP process done, we can re enable interrupts
    SYS_enableInts();

    // Plane scroll
    VDP_setScrollingMode(HSCROLL_PLANE, VSCROLL_PLANE);

    u8 offset = 0;
    while(1){
        if(onTitle)VDP_setVerticalScroll(BG_B, offset += 1);
        if(game_on){
            VDP_setVerticalScroll(BG_B, offset += 1);
            if(player.x < LEFT_EDGE) player.x = LEFT_EDGE;
            if(player.x > RIGHT_EDGE) player.x = 208;
            if(hit) hitTimer--;
            if(shield){
                shieldTimer--;
            }
            updateHealthDisplay();
            if(hitTimer < 1) hit = FALSE;
            if(shieldTimer < 1){
                shield = FALSE;
                SPR_setVisibility(shield_sprite, HIDDEN);
            }
            SPR_setPosition(player.sprite, player.x, player.y);
            SPR_setPosition(shield_sprite, player.x, player.y + 16);
            moveCoins();
            moveEnemies();
            SPR_update();
        }
        SYS_doVBlankProcess();
    }
    return 0;
}