#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include "drivetrain.hpp"

class Autonomous {
public:
    Autonomous(Drivetrain &drivetrain);
    void run();

private:
    Drivetrain &drivetrain;
};

#endif // AUTONOMOUS_HPP
