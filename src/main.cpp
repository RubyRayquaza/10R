#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/lcd.hpp"
#include "pros/vision.hpp"
#include "lemlib/Drivetrain.hpp"
#include "lemlib/ControllerSettings.hpp"
#include "lemlib/Chassis.hpp"
#include "drivetrain.hpp"

// Define global motor groups and drivetrain settings
pros::MotorGroup left_motor_group({-1, 2, -3}, pros::MotorGears::blue);
pros::MotorGroup right_motor_group({4, -5, 6}, pros::MotorGears::blue);

lemlib::Drivetrain drivetrain(&left_motor_group, 
                              &right_motor_group, 
                              24, // 24-inch track width
                              lemlib::Omniwheel::NEW_375, 
                              400, // drivetrain RPM
                              2); // horizontal drift

// Define PID controller settings
lemlib::ControllerSettings lateral_controller(10, 0, 3, 3, 1, 100, 3, 500, 20);
lemlib::ControllerSettings angular_controller(2, 0, 10, 3, 1, 100, 3, 500, 0);

// Create the chassis
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller);

// Function prototypes
void initialize();
void autonomous();
void opcontrol();

// Main function
int main() {
    initialize(); // Initialize robot components

    // Main control loop
    while (true) {
        // Call operator control function (driver control)
        opcontrol();
        pros::delay(20); // Small delay to prevent CPU overload
    }

    return 0; // Not reached, but good practice
}

// Initialization function
void initialize() {
    pros::lcd::initialize(); // Initialize the LCD screen
    chassis.calibrate(); // Calibrate sensors if used

    // Additional initialization code can be added here
    pros::lcd::print(0, "Robot Initialized");
}

// Autonomous function
void autonomous() {
    // Implement autonomous behavior here
}

// Operator Control function
void opcontrol() {
    // Initialize PID variables
    double targetSpeedLeft, targetSpeedRight;
    double currentSpeedLeft, currentSpeedRight;

    // Loop forever
    while (true) {
        // Get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        // Set target speeds based on joystick inputs
        targetSpeedLeft = leftY;
        targetSpeedRight = rightY;

        // Calculate PID output for left motors
        currentSpeedLeft = left_motor_group.get_velocity(); // Get current speed
        double leftOutput = lateral_controller.calculate(targetSpeedLeft, currentSpeedLeft);

        // Calculate PID output for right motors
        currentSpeedRight = right_motor_group.get_velocity(); // Get current speed
        double rightOutput = lateral_controller.calculate(targetSpeedRight, currentSpeedRight);

        // Move the robot using PID outputs
        left_motor_group.move_velocity(leftOutput);
        right_motor_group.move_velocity(rightOutput);

        // Delay to save resources
        pros::delay(25);
    }
}
