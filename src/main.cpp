#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/vision.hpp"
#include "lemlib/Drivetrain.hpp"
#include "lemlib/ControllerSettings.hpp"
#include "lemlib/Chassis.hpp"
#include "drivetrain.hpp"

// Motor groups for left and right motors
pros::MotorGroup left_motor_group({-1, 2, -3}, pros::MotorGears::blue);
pros::MotorGroup right_motor_group({4, -5, 6}, pros::MotorGears::blue);

// Create an instance of the Drivetrain class
Drivetrain drivetrain(&left_motor_group, &right_motor_group);

// Controller setup
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Initialize function
void initialize() {
    pros::lcd::initialize(); // Initialize brain screen
    // Any additional initialization code
}

// Operator control function
void opcontrol() {
    while (true) {
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        // Control left motors
        if (leftY > 0) {
            drivetrain.moveForward(leftY); // Forward movement
        } else if (leftY < 0) {
            drivetrain.moveBackward(-leftY); // Backward movement
        } else {
            drivetrain.stop(); // Stop
        }

        // Handle right motor control similarly
        if (rightY > 0) {
            drivetrain.moveForward(rightY); // Forward movement for right
        } else if (rightY < 0) {
            drivetrain.moveBackward(-rightY); // Backward movement for right
        }

        pros::delay(25); // Delay to save resources
    }
}

// Main function
int main() {
    initialize(); // Call initialization function
    pros::lcd::initialize(); // Re-initialize brain screen if needed
    opcontrol(); // Start operator control
    return 0;
}
