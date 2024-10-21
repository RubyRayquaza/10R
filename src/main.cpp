#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/vision.hpp"
#include "lemlib/Drivetrain.hpp"
#include "lemlib/ControllerSettings.hpp"
#include "lemlib/Chassis.hpp"

// Motor group setup
pros::MotorGroup left_motor_group({-1, 2, -3}, pros::MotorGears::blue);
pros::MotorGroup right_motor_group({4, -5, 6}, pros::MotorGears::blue);

// Drivetrain settings
Drivetrain drivetrain(&left_motor_group, &right_motor_group);

// Controller setup
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Opcontrol function for driver control
void opcontrol() {
    while (true) {
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        drivetrain.tank(leftY, rightY); // Use tank drive method

        pros::delay(25); // Delay to save resources
    }
}

// Initialize function
void initialize() {
    pros::lcd::initialize(); // Initialize brain screen
    // Additional initialization can go here
}
