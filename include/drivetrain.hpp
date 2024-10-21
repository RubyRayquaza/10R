#ifndef DRIVETRAIN_HPP
#define DRIVETRAIN_HPP

#include "lib/pros/motors.hpp"

class Drivetrain {
public:
    Drivetrain(pros::MotorGroup* leftMotors, pros::MotorGroup* rightMotors);
    void moveForward(int velocity);
    void moveBackward(int velocity);
    void tank(int leftY, int rightY);
    void stop();

private:
    pros::MotorGroup* left_motors;
    pros::MotorGroup* right_motors;
};

#endif // DRIVETRAIN_HPP
