#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/vision.hpp"
#include "lemlib/Drivetrain.hpp"
#include "lemlib/ControllerSettings.hpp"
#include "lemlib/Chassis.hpp"
#include "controller.hpp"
#include "autonomous.hpp"

// Motor and Chassis setup
pros::MotorGroup left_motor_group({-1, 2, -3}, pros::MotorGears::blue);
pros::MotorGroup right_motor_group({4, -5, 6}, pros::MotorGears::blue);

lemlib::Drivetrain drivetrain(&left_motor_group, &right_motor_group, 24, lemlib::Omniwheel::NEW_375, 400, 2);
lemlib::Chassis chassis(drivetrain, /* PID settings */);

// Controller setup
pros::Controller controller(pros::E_CONTROLLER_MASTER);
Controller ctrl(controller);

// Autonomous setup
Autonomous autonomous(drivetrain);

// Initialize function
void initialize() {
    pros::lcd::initialize();
    chassis.calibrate();
    // Add any additional initialization logic here
}

// Operator Control
void opcontrol() {
    while (true) {
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        // Use the controller to drive the tank
        ctrl.driveTank(leftY, rightY);

        pros::delay(25);
    }
}

// Autonomous control
void autonomous() {
    autonomous.run();
}
