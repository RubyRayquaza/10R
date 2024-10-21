#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "drivetrain.hpp"

class Controller {
public:
    Controller(pros::E_CONTROLLER_ID id, Drivetrain &drivetrain);
    void driveTank();

private:
    pros::Controller controller;
    Drivetrain &drivetrain; // Reference to the drivetrain
};

#endif // CONTROLLER_HPP
