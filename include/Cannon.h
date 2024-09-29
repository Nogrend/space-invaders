#ifndef CANNON_H
#define CANNON_H

#include <Arduino.h>

class Cannon {
private:
    int playerX;            // Player's current X position
    int playerXPrevious;    // Player's previous X position
    int projectileX;        // Projectile X position
    int projectileY;        // Projectile Y position
    int &disp;     // Reference to the display object
    int matrixWidth;        // Width of the matrix (32)
    int matrixHeight;       // Height of the matrix (32)

    // Private method for coordinate mapping
    void mapCoordinates(int logicalX, int logicalY, int &hardwareX, int &hardwareY);

public:
    // Constructor
    Cannon(int &matrix, int width, int height);

    // Player movement methods
    void moveLeft();
    void moveRight();

    // Shooting methods
    void shoot();
    void updateProjectile();

    // Draw player on the matrix
    void updatePlayer();
};

#endif