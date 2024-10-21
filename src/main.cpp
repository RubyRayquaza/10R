#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/vision.hpp"
#include "lemlib/Drivetrain.hpp"
#include "lemlib/ControllerSettings.hpp"
#include "lemlib/Chassis.hpp"
#include "pid.hpp"
#include "controller.hpp"
#include "autonomous.hpp"

// Initialize motor groups and drivetrain
pros::MotorGroup left_motor_group({-1, 2, -3}, pros::MotorGears::blue);
pros::MotorGroup right_motor_group({4, -5, 6}, pros::MotorGears::blue);

lemlib::Drivetrain drivetrain(&left_motor_group, &right_motor_group, 24, lemlib::Omniwheel::NEW_375, 400, 2);
lemlib::ControllerSettings lateral_controller(10, 0, 3, 3, 1, 100, 3, 500, 20);
lemlib::ControllerSettings angular_controller(2, 0, 10, 3, 1, 100, 3, 500, 0);
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller);
Autonomous autonomous(drivetrain); // Create an Autonomous instance

// Create a Controller instance
Controller controller(pros::E_CONTROLLER_MASTER, drivetrain);

void initialize() {
    pros::lcd::initialize();
    chassis.calibrate();
}

void opcontrol() {
    while (true) {
        controller.driveTank(); // Use the driveTank method from the Controller class
        pros::delay(20);
    }
}

int main() {
    initialize();

    // Example condition to start autonomous
    bool isAutonomous = true; // Change this to control mode selection

    if (isAutonomous) {
        autonomous.run(); // Call the run method of the Autonomous class
    } else {
        opcontrol();
    }

    return 0;
}
