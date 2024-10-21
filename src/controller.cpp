#include "controller.hpp"

Controller::Controller(pros::E_CONTROLLER_ID id, Drivetrain &drivetrain)
    : controller(id), drivetrain(drivetrain) {}

void Controller::driveTank() {
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    if (leftY == 0 && rightY == 0) {
        drivetrain.stop(); // Call stop method from the drivetrain
    } else {
        drivetrain.tank(leftY, rightY); // Use the drivetrain's tank method
    }
}
