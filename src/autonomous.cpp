#include "include/autonomous.hpp"

Autonomous::Autonomous(Drivetrain &drivetrain)
    : drivetrain(drivetrain) {}

void Autonomous::run() {
    // Example autonomous actions (Change later)
    drivetrain.moveForward(100); // Move forward at a speed/velocity of 100
    pros::delay(2000); // Delay for 2 seconds
    
    // Stopping drivetrain; auton complete
    drivetrain.stop(); // Stop the robot

    // Add more autonomous behaviors here
}
