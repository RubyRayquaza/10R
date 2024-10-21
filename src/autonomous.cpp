#include "autonomous.hpp"

Autonomous::Autonomous(Drivetrain &dt) : drivetrain(dt) {}

void Autonomous::run() {
    // Example autonomous routine
    drivetrain.moveForward(100); // Move forward
    pros::delay(2000); // Wait for 2 seconds
    drivetrain.stop(); // Stop motors
}
