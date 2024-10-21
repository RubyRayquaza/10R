#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "lib/pros/adi.hpp"
#include "lib/pros/motors.hpp"
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
