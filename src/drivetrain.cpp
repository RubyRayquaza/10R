#include "drivetrain.hpp"

// Constructor implementation
Drivetrain::Drivetrain(pros::MotorGroup* leftMotors, pros::MotorGroup* rightMotors)
    : left_motors(leftMotors), right_motors(rightMotors) {}

void Drivetrain::moveForward(int velocity) {
    left_motors->move_velocity(velocity);
    right_motors->move_velocity(velocity);
}

void Drivetrain::moveBackward(int velocity) {
    left_motors->move_velocity(-velocity);
    right_motors->move_velocity(-velocity);
}

void Drivetrain::tank(int leftY, int rightY) {
    if (leftY == 0 && rightY == 0) {
        stop(); // Stop if both joysticks are neutral
    } else {
        left_motors->move_velocity(leftY); // Forwards/backwards based on left joystick
        right_motors->move_velocity(rightY); // Forwards/backwards based on right joystick
    }
}

void Drivetrain::stop() {
    left_motors->move_velocity(0);
    right_motors->move_velocity(0);
}
