#include "pid.hpp"

// Constructor implementation
PID::PID(double kp, double ki, double kd)
    : kp(kp), ki(ki), kd(kd), integral(0), previous_error(0) {}

double PID::calculate(double setpoint, double actual) {
    double error = setpoint - actual;
    integral += error;
    double derivative = error - previous_error;
    previous_error = error;

    return (kp * error) + (ki * integral) + (kd * derivative);
}
