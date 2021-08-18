#include "scenes.h"

u16 index;

void titleScreen(){
    onTitle = TRUE;
    index += TILE_USERINDEX;
    VDP_setTextPlane(BG_A);
    VDP_setTextPalette(PAL0);
    VDP_setPalette(PAL0, title.palette->data);
    VDP_setPalette(PAL1, bg_B.palette->data);
    VDP_drawImageEx(BG_A, &title, TILE_ATTR_FULL(PAL0, 1, FALSE, FALSE, index),0, 0, FALSE, DMA);

    index += title.tileset->numTile;

    VDP_drawText(msg_start, 20 - strlen(msg_start)/2, 23);

    VDP_drawImageEx(BG_B, &bg_B, TILE_ATTR_FULL(PAL1, 0, FALSE, FALSE, index), 0, 0, FALSE, DMA);

    index += bg_B.tileset->numTile;
}

void level(){
    onTitle = FALSE;
    VDP_clearText(0, 23, 32);
    VDP_setTextPlane(WINDOW);
    VDP_setPalette(PAL2, ui.palette->data);
    VDP_setTextPalette(PAL2);
    VDP_clearPlane(BG_A, FALSE);
    VDP_setWindowVPos(FALSE, 1);
    //VDP_drawImageEx(WINDOW, &ui, TILE_ATTR_FULL(PAL2, 0, FALSE, FALSE, index), 0, 0, FALSE, DMA);
    VDP_drawText(label_score, 10, 0);
    VDP_drawText(str_score, 17, 0);
    VDP_drawText(str_coins, 22, 0);
    reviveCharacter(&player);
    SPR_setAnim(player.sprite, ANIM_WALK);
    coin_counter_sprite = SPR_addSprite(&coin_ui, 160, 0, TILE_ATTR(PAL2, 1, FALSE, FALSE));
    heart_ui = SPR_addSprite(&heart, 216, 0,TILE_ATTR(PAL2, 1, FALSE, FALSE));
}