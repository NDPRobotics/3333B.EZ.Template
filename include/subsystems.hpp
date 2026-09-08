#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// Intake
inline pros::Motor motorleft(1);
inline pros::Motor motorright(2);
inline pros::MotorGroup intake({1, 2});

// Cylinders
inline ez::Piston intake_lift('A');
inline ez::Piston claw('B');

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');