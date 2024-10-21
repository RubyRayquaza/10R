#include "autonomous.hpp"

// Constructor implementation
Autonomous::Autonomous(Drivetrain &drivetrain)
    : drivetrain(drivetrain) {}

void Autonomous::run() {
    // Move forward at a moderate speed
    drivetrain.moveForward(50); // Move forward at a velocity of 50
    pros::delay(2000); // Move for 2 seconds

    // Stop the drivetrain
    drivetrain.stop(); // Stop the drivetrain
    pros::delay(500);  // Wait for half a second

    // Optional: Add more autonomous behaviors here
}
