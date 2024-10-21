#include "lib/pros/adi.hpp"
#include "lib/pros/motors.hpp"
#include "lib/pros/vision.hpp"
#include "lib/lemlib/Drivetrain.hpp"
#include "lib/lemlib/ControllerSettings.hpp"
#include "lib/lemlib/Chassis.hpp"
#include "include/pid.hpp"
#include "include/controller.hpp"
#include "include/autonomous.hpp"
#include "include/drivetrain.hpp"
#include "include/screen.hpp"

// Initialize motor groups and drivetrain
pros::MotorGroup left_motor_group({-1, 2, -3}, pros::MotorGears::blue);
pros::MotorGroup right_motor_group({4, -5, 6}, pros::MotorGears::blue);

lemlib::Drivetrain drivetrain(&left_motor_group, &right_motor_group, 24, lemlib::Omniwheel::NEW_375, 400, 2);
lemlib::ControllerSettings lateral_controller(10, 0, 3, 3, 1, 100, 3, 500, 20);
lemlib::ControllerSettings angular_controller(2, 0, 10, 3, 1, 100, 3, 500, 0);
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller);
Autonomous autonomous(drivetrain); // Create an Autonomous instance
Screen screen; // Create a screen instance

void initialize() {
    screen.initialize(); // Initialize the screen
    pros::lcd::initialize(); // Initialize the LCD screen
    chassis.calibrate();
}

void opcontrol() {
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    while (true) {
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        chassis.tank(leftY, rightY);
        // Updating the screen with the current position (dummy values for x, y, theta)
        screen.update(0.0f, 0.0f, 0.0f); // Replace with actual values if/when using sensors
        pros::delay(20);
    }
}

int main() {
    initialize();

    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    // Wait for user input to select mode
    while (true) {
        // Check if the L1 button is pressed for autonomous
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            autonomous.run(); // Call the run method of the Autonomous class
            break; // Exit the loop to start driver control
        }

        // Check if the L2 button is pressed for driver control
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            break; // Exit the loop to start driver control
        }

        pros::delay(20); // Small delay to prevent busy-waiting
    }

    // Start driver control after exiting the loop
    opcontrol();

    return 0;
}
