// Track Width: 24"
// Wheelbase: 24"
// Horizontal Drift: N/A
// left motors on ports 1, 2, 3; 1 & 3 are negative ports (backwards); uses blue motors (600 RPM)
pros::MotorGroup left_motor_group({-1, 2, -3}, pros::MotorGears::blue);
// right motors on ports 4, 5, 6; 5 is a negative port (backwards); uses blue motors (600 RPM)
pros::MotorGroup right_motor_group({4, -5, 6}, pros::MotorGears::blue);

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_motor_group, // left motor group
                              &right_motor_group, // right motor group
                              24, // 24 inch track width
                              lemlib::Omniwheel::NEW_375, // using new 3.75" omnis
                              400, // drivetrain rpm is 400
                              2 // horizontal drift is 2 (for now)
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);
