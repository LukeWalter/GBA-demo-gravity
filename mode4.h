#ifndef GBA_MODE4_H
#define GBA_MODE4_H

#include "gba.h"

#define FRONTBUFFER ((unsigned short*) 0x06000000) // Beginning of front buffer
#define BACKBUFFER  ((unsigned short*) 0x0600A000) // Beginning of back buffer

#define setPixel4(x, y, colorIndex) (videoBuffer[OFFSET(x, y, SCREENWIDTH) / 2] = (videoBuffer[OFFSET(x, y, SCREENWIDTH) / 2] & (0xFF00 >> (8 * ((x) & 1)))) | (colorIndex << (8 * ((x) & 1))))

void flipPages();
void drawRectangle4(int x, int y, int width, int height, volatile u8 colorIndex);
void fillScreen4(volatile u8 colorIndex);
void drawImage4(int x, int y, int width, int height, const u16* image);
void drawFullscreenImage4(const unsigned short* image);

#endif