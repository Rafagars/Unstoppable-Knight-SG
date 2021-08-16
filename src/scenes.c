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
}