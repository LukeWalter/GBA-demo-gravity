#ifndef GRAVITY_DEMO_H
#define GRAVITY_DEMO_H

#include "gba.h"
#include "print.h"
#include "mode4.h"

// ~~ GRAVITY STUFF ~~

#define GRAVITY 80 // How fast things fall
#define TERMINALVELOCITY 1300 // Fastest possible fall speed

// For 8.8 fixed point encoding
#define SHIFTUP(n) ((n) << 8)
#define SHIFTDOWN(n) ((n) >> 8)

// ~~~~~~~~~~~~~~~~~~~~

// Returns value if min <= value <= max, returns min if value < min, returns max if value > max
#define CLAMP(value, min, max) (((min) * ((value) < (min))) + ((max) * ((value) > (max))) + ((value) * ((value) >= (min) && (value) <= (max))))

// Returns value if value >= floor, returns floor if value < floor
#define FLOOR(value, floor) ((floor) * ((value) < (floor)) + (value) * ((value) >= (floor)))

// Returns value if value <= ceiling, returns ceiling if value > ceiling
#define CEILING(value, ceiling) ((ceiling) * ((value) > (ceiling)) + (value) * ((value) <= (ceiling)))

typedef enum { WHITE_ID, GREY_ID, RED_ID } PAL_ID;

typedef struct {
    int x, y, width, height;
    
} HITBOX;

typedef struct {
    int x, y, width, height;
    int dx, dy;
    int grounded;
    int jumpCount;
    int jumpForce;
    u8 colorIndex;
    
} PLAYER;

PLAYER player;
HITBOX ground;

void initialize();
void update();
void draw();

#endif