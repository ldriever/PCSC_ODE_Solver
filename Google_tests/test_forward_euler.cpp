#include "gtest/gtest.h"
#include "test_ode.cpp"
#include "forward_euler.cpp"

struct ForwardEulerTest : ODETest
{
    class ForwardEuler* ode;
    int method_accuracy = 1;
    ForwardEulerTest()
    {
        ode = new ForwardEuler(*test_setup);
    }
    virtual ~ForwardEulerTest()
    {
        delete ode;
    }
};

TEST_F(ForwardEulerTest, TestSolution) {
    E::ArrayXd solution = ode->Solve();
    ASSERT_EQ(test_setup->t.size(), solution.size()); // Check that the t and y arrays are of equal size
    ASSERT_NEAR(solution(E::last), exact_solution, abs(0.01 * exact_solution)); // Check that the solution is within 1% of the exact solution
};

TEST_F(ForwardEulerTest, TestConvergence) {
    // first create a new version of the ode with halved step size
    auto refined_test_setup = new class SetUp("test_settings.txt");
    refined_test_setup->dt = test_setup->dt / 2;
    refined_test_setup->N = test_setup->N * 2;
    refined_test_setup->solution_size = test_setup->solution_size * 2 - 1;
    auto refined_ode = ForwardEuler(*refined_test_setup);

    auto error = abs(ode->Solve()(E::last) - exact_solution);
    auto refined_error = abs(refined_ode.Solve()(E::last) - exact_solution);

    delete refined_test_setup;

    ASSERT_NEAR(error / refined_error, std::pow(2, method_accuracy), 0.1); // Check that the solution is within 1% of the exact solution
};