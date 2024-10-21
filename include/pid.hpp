#ifndef PID_HPP
#define PID_HPP

class PID {
public:
    PID(double kp, double ki, double kd);
    double calculate(double setpoint, double actual);

private:
    double kp;
    double ki;
    double kd;
    double integral;
    double previous_error;
};

#endif // PID_HPP
