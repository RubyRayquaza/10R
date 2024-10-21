#include "controller.hpp"

Controller::Controller(pros::Controller &ctrl) : controller(ctrl) {}

void Controller::driveTank(int leftY, int rightY) {
    // Tank drive method to control motors based on joystick inputs
    if (leftY == 0 && rightY == 0) {
        // Stop if both joysticks are neutral
        // You can call a stop method from the drivetrain here if needed
    } else {
        // Move motors based on joystick inputs
        // Assuming you have access to the drivetrain instance here
        // drivetrain.tank(leftY, rightY); // This line requires context
    }
}
