#include "include/drivetrain.hpp"

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
    left_motors->move_velocity(leftY);
    right_motors->move_velocity(rightY);
}

void Drivetrain::stop() {
    left_motors->move_velocity(0);
    right_motors->move_velocity(0);
}
