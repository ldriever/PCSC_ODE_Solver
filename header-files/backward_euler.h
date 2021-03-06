//
// Created by Leonhard Driever on 08.12.21.
//

#ifndef ODE_SOLVER_PROJECT_BACKWARD_EULER_H
#define ODE_SOLVER_PROJECT_BACKWARD_EULER_H

#include "ode_parent.h"
#include "setup.h"

/**
This class is a child of the ODE class to implement the step of the Backward Euler algorithm
*/

class BackwardEuler: public ODE {

public:
    
    BackwardEuler(SetUp &user_setup);

protected:
    /**
    Backward Euler algorithm only requires the knowledge of the initial value of the y array
    */
    int method_length = 1;

    /**
    Needed to implement the step of the Backward Euler algorithm
    */
    double OneStep(double t);


    /**
    Returns the required number of initial y elements needed to implement one step of the Runge Kutta algorithm
    */
    int GetMethodLength() {return method_length;};
};

#endif //ODE_SOLVER_PROJECT_BACKWARD_EULER_H
