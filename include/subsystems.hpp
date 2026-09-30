#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// Intake
inline pros::MotorGroup intake({-14, 13});

// Cylinders
inline pros::Motor l_lift(1);
inline pros::Motor r_lift(-2);

inline void set_lift(int input) {
  l_lift.move(input);
  r_lift.move(input);
}

inline ez::Piston claw('A');

inline ez::Piston wrist('B');

inline ez::Piston ramp('C');

inline ez::PID liftPID{0.45, 0, 0, 0, "Lift"};

inline void lift_wait() {
  while (liftPID.exit_condition({l_lift, r_lift}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}

inline void lift_macro() {
  ramp.set(true);
  liftPID.target_set(50);
  wrist.set(false);
  pros::delay(1000);
  ramp.set(false);
}
// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');