//
// Created by Leonhard Driever on 03.12.21.
//

#ifndef ODE_SOLVER_PROJECT_ODE_CLASS_H
#define ODE_SOLVER_PROJECT_ODE_CLASS_H

#include <Eigen/Dense>
#include 'setup.h'

namespace E = Eigen;

class ODE{

public:
    explicit ODE(SetUp UserSetUp);
    void Solve();

protected:
    const double dt;
    const double t_0;
    const double x;
    const int N
    const int method_length;
    E::Array<double, method_length, 1> y_short_term; // Static size is applicable as it is dependent on the method and does not change
    E::ArrayXd & y;
    const E::ArrayXd & t;

    double RHS;
    virtual void InitializeYShortTerm();
    virtual double OneStep(double t) = 0;

private:
    const int sampling_frequency;

    void DocumentYShortTerm()
    void UpdateYShortTerm(double y_new);

};

#endif //ODE_SOLVER_PROJECT_ODE_CLASS_H
