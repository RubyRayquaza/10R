#ifndef DRIVETRAIN_HPP
#define DRIVETRAIN_HPP

#include "pros/motors.hpp"
#include "lemlib/Drivetrain.hpp"
#include "lemlib/ControllerSettings.hpp"

// Function prototypes
void initializeDrivetrain();

extern pros::MotorGroup left_motor_group;
extern pros::MotorGroup right_motor_group;
extern lemlib::Drivetrain drivetrain;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;

#endif // DRIVETRAIN_HPP
