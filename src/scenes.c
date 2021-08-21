#include "scenes.h"

u16 index;

void titleScreen(){
    onTitle = TRUE;
    index += TILE_USERINDEX;
    VDP_setTextPlane(BG_A);
    VDP_setTextPalette(PAL0);
    VDP_drawImageEx(BG_A, &title, TILE_ATTR_FULL(PAL0, 1, FALSE, FALSE, index),0, 0, FALSE, DMA);

    index += title.tileset->numTile;

    VDP_drawText(msg_start, 20 - strlen(msg_start)/2, 23);

    VDP_drawImageEx(BG_B, &bg_B, TILE_ATTR_FULL(PAL1, 0, FALSE, FALSE, index), 0, 0, FALSE, DMA);

    index += bg_B.tileset->numTile;
}

void level(){
    onTitle = FALSE;
    VDP_clearText(0, 23, 32);
    VDP_setTextPalette(PAL2);
    VDP_clearTextAreaBG(BG_A, 0, 1, 40, 32);
    VDP_drawText(label_score, 10, 0);
    VDP_drawText(str_score, 16, 0);
    VDP_drawText(str_coins, 22, 0);
    player.health = 3;
    SPR_setAnim(player.sprite, ANIM_WALK);
    coin_counter_sprite = SPR_addSprite(&coin_ui, 160, 0, TILE_ATTR(PAL2, 1, FALSE, FALSE));
    heart_ui = SPR_addSprite(&heart, 216, 0,TILE_ATTR(PAL2, 1, FALSE, FALSE));
    setupCoins();
}