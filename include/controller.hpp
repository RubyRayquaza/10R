#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "pros/adi.hpp"
#include "pros/motors.hpp"

class Controller {
public:
    Controller(pros::E_CONTROLLER_ID id);
    int getLeftY();
    int getRightY();

private:
    pros::Controller controller;
};

#endif // CONTROLLER_HPP
