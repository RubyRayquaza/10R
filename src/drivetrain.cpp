#include "drivetrain.hpp"

// Constructor implementation
Drivetrain::Drivetrain(pros::MotorGroup* leftMotors, pros::MotorGroup* rightMotors)
    : left_motors(leftMotors), right_motors(rightMotors) {}

// Move forward at a specified velocity
void Drivetrain::moveForward(int velocity) {
    left_motors->move_velocity(velocity);
    right_motors->move_velocity(velocity);
}

// Move backward at a specified velocity
void Drivetrain::moveBackward(int velocity) {
    left_motors->move_velocity(-velocity);
    right_motors->move_velocity(-velocity);
}

// Tank drive method to control motors based on joystick inputs
void Drivetrain::tank(int leftY, int rightY) {
    left_motors->move_velocity(leftY);
    right_motors->move_velocity(rightY);
}

// Stop the motors
void Drivetrain::stop() {
    left_motors->move_velocity(0);
    right_motors->move_velocity(0);
}
