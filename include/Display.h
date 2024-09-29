#ifndef DISPLAY_H
#define DISPLAY_H
#include <stdint.h>

#define NUMBER_OF_DISPLAYS 16
#define CS 4

class Display {
public:
    Display();

    ~Display();

    void update();

    void draw();

private:
    uint32_t grid[32] = {0};

    // void convertGridToLedMatrix(const uint32_t grid[32], ??& matrix);
};

#endif //DISPLAY_H
