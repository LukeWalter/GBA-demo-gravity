#include "gba.h"
#include "print.h"
#include "mode4.h"

#include "demo.h"

void initialize() {
    
    mgba_open();

    REG_DISPCTL = MODE(4) | BG_ENABLE(2) | DISP_BACKBUFFER;

    buttons = REG_BUTTONS;
    oldButtons = 0;

    BG_PALETTE[0] = WHITE;
    BG_PALETTE[1] = RGB(8, 8, 8);
    BG_PALETTE[2] = RED;

    player.x = 110;
    player.dx = 2;
    player.width = 20;
    player.height = 20;
    player.colorIndex = RED_ID;

    player.y = 20; // 8.8 encoded value (shift up for encoding, shift down for real value)
    player.dy = 0; // 8.8 encoded value (shift up for encoding, shift down for real value)
    // Add members for grounded, jumps & jumpForce


    ground.x = 0;
    ground.y = 140;
    ground.width = SCREENWIDTH;
    ground.height = 20;

}

void update() {

    // X movement
    int direction = !!BUTTON_HELD(BUTTON_RIGHT) - !!BUTTON_HELD(BUTTON_LEFT);
    player.x = CLAMP(player.x + player.dx * direction, 0, SCREENWIDTH - player.width);

    // ~~ Y movement (Gravity!) ~~

    // Get the y value just underneath the player


    // Determine if player is grounded (use your collision map for this step if you're using one!!)


    // Logic for grounded player
    if (player.grounded) {

        // Set player velocity to 0


        // Restore player's jumps
        

    // Logic for airbourne player
    } else {
        
        // Accelerate player's velocity downward by GRAVITY (max velocity of TERMINALVELOCITY)

        
        // Check if player is going to hit the ground next frame (use your collision map for this step if you're using one!!)


        // Match y velocity with distance from ground if close


        // mgba_printf("Distance to ground: %d | Velocity: %d", ground.y - bottomY, SHIFTDOWN(player.dy));

    }

    // Allow the player to jump based on condition specified here
    int jumpCondition = 1;

    // If jump button is pressed and jump condition is met
    if (BUTTON_PRESSED(BUTTON_A) && jumpCondition) {

        // Set y velocity to initial velocity for jump
        
        
        // Burn a jump
        

    }

    // Update the player's y position using its current y velocity
    player.y += player.dy;

} // update

void draw() {
    fillScreen4(WHITE_ID);
    drawRectangle4(ground.x, ground.y, ground.width, ground.height, GREY_ID);
    drawRectangle4(player.x, player.y, player.width, player.height, player.colorIndex);

} // draw

int main() {

    initialize();

    while (1) {
        
        oldButtons = buttons;
        buttons = REG_BUTTONS;

        update();
        draw();
        waitForVBlank();
        flipPages();

    }
    
    return 0;

}