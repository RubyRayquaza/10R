#include "screen.hpp"

// Constructor
Screen::Screen() {}

// Initialize the LCD screen
void Screen::initialize() {
    pros::lcd::initialize();
}

// Clear the screen
void Screen::clear() {
    pros::lcd::clear();
}

// Update the screen with the latest values
void Screen::update(float x, float y, float theta) {
    clear();
    pros::lcd::print(0, "X: %.2f", x);
    pros::lcd::print(1, "Y: %.2f", y);
    pros::lcd::print(2, "Theta: %.2f", theta);
}
