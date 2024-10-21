#ifndef PID_HPP
#define PID_HPP

class PID {
public:
    PID(double kP, double kI, double kD);
    
    // Method to calculate the PID output
    double calculate(double setpoint, double current);

    // Method to reset the PID controller
    void reset();

private:
    double kP; // Proportional gain
    double kI; // Integral gain
    double kD; // Derivative gain

    double previous_error; // Previous error value
    double integral;       // Integral of the error
};

#endif // PID_HPP
