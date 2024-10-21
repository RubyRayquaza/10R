#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "pros/adi.hpp"
#include "pros/motors.hpp"

class Controller {
public:
    Controller(pros::Controller &controller);
    void driveTank(int leftY, int rightY);

private:
    pros::Controller &controller;
};

#endif // CONTROLLER_HPP
