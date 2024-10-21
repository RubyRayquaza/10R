#include "controller.hpp"

// Constructor implementation
Controller::Controller(pros::E_CONTROLLER_ID id) : controller(id) {}

// Get left joystick Y value
int Controller::getLeftY() {
    return controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
}

// Get right joystick Y value
int Controller::getRightY() {
    return controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
}
