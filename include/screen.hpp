#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "pros/lcd.hpp"

class Screen {
public:
    Screen();
    void initialize();
    void update(float x, float y, float theta);

private:
    void clear();
};

#endif // SCREEN_HPP
