#include "Display.h"


Display::Display(): display(CS, NUMBER_OF_DISPLAYS) {
    display.begin(); // Starts the display
    display.setIntensity(0x04); // Set LED intensity
}

Display::~Display() = default;

void Display::update() {
    this->convertGridToLedMatrix(grid, display);
}

void Display::draw() {
    grid[0] = 0x0f000;
    this->update();
}

void Display::convertGridToLedMatrix(const uint32_t grid[32], simpleMatrix &matrix) {
    // Iterate over each pixel in the 32x32 grid
    uint8_t moduleGrid[16][8] = {0x00};
    uint8_t modules[16][8];

    uint8_t horizontalModules = 4;

    for (byte pixelRow = 0; pixelRow < 32; pixelRow++) {
        byte moduleRow = (byte) (pixelRow % 8);
        byte idk = (byte) (pixelRow / 8);

        uint32_t row = grid[pixelRow];

        for (int moduleColumn = 0; moduleColumn < horizontalModules; moduleColumn++) {
            uint8_t segmentRow = row >> 8 * moduleColumn;
            int moduleNumber = (idk * 4) + moduleColumn;

            modules[moduleNumber][moduleRow] = segmentRow;
        }
    }
    // display.();
}
