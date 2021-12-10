//
// Created by Leonhard Driever on 05.12.21.
//

#include "forward_euler.h"
#include "setup.h"

ForwardEuler::ForwardEuler(SetUp user_setup) : ODE (user_setup) {};

double ForwardEuler::OneStepFE(double t) {
    return y_short_term(0) + dt * RHS(y_short_term(0), t - dt, x);
}

