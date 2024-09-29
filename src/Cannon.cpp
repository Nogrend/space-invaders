#include "Cannon.h"

// Constructor
Cannon::Cannon(int &matrix, int width, int height)
  : disp(matrix), matrixWidth(width), matrixHeight(height), playerX(0), playerXPrevious(-1), projectileX(-1), projectileY(-1) {}

// Method to map logical 32x32 grid coordinates to hardware coordinates
void Cannon::mapCoordinates(int logicalX, int logicalY, int &hardwareX, int &hardwareY) {
    int blockRow = logicalY / 8;  // Determine block row
    int blockCol = logicalX / 8;  // Determine block column
    int localX = logicalX % 8;    // X within block
    int localY = logicalY % 8;    // Y within block

    // Map to hardware coordinates
    hardwareX = blockCol * 8 + localX;
    hardwareY = blockRow * 8 + localY;
}

// Move the player left
void Cannon::moveLeft() {
    if (playerX > 0) {
        playerX--;
    }
}

// Move the player right
void Cannon::moveRight() {
    if (playerX < matrixWidth - 1) {
        playerX++;
    }
}

// Shoot projectile
void Cannon::shoot() {
    if (projectileY == -1) { // If no projectile is currently active
        projectileX = playerX; // Projectile starts at player's current position
        projectileY = 0; // Start at the bottom
    }
}

// Update the projectile's movement
void Cannon::updateProjectile() {
    if (projectileY >= 0) { // If a projectile exists
        int hardwareX, hardwareY;
        mapCoordinates(projectileX, projectileY, hardwareX, hardwareY); // Map to hardware coordinates
        // disp.clearPixel(hardwareX, hardwareY); // Clear previous position

        projectileY++; // Move up

        if (projectileY <= matrixHeight - 1) { // If within bounds
            mapCoordinates(projectileX, projectileY, hardwareX, hardwareY);
            // disp.setPixel(hardwareX, hardwareY); // Draw at new position
        } else {
            projectileY = -1; // Reset when off screen
        }
    }
}

// Update player's position on the display
void Cannon::updatePlayer() {
    int hardwareX, hardwareY;

    // Map and display the player at the new position
    mapCoordinates(playerX, 1, hardwareX, hardwareY);
    // disp.setPixel(hardwareX, hardwareY);

    // Clear the previous player position
    if (playerXPrevious != -1) {
        mapCoordinates(playerXPrevious, 1, hardwareX, hardwareY);
        // disp.clearPixel(hardwareX, hardwareY);
    }

    playerXPrevious = playerX; // Update previous position tracker
}
