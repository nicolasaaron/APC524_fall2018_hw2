#ifndef RUNGE_KUTTA_H_
#define RUNGE_KUTTA_H_


#include "integrator.h"
class Model;                   // Forward declaration
// Above is better than include-ing "model.h" b/c the Euler class
// doesn't need to know anything about how Model works, just that
// there is a data type (i.e. a class) called "Model"

// Fixed-timestep Euler integrator
class RungeKutta4 : public Integrator
{
public:
   RungeKutta4(double dt, const Model &model);
   ~RungeKutta4();

   int Step(double t, double *x);

private:
   const double dt_;	       // integration timestep

   const Model &model_;	       // object w/ info about ODE system,
			       // including dimension of state vector
			       // and function f(x,t) for evaluating
			       // derivative of the state vector

   const int dimen_;           // dimension of state vector x
   double *k1, *k2, *k3, *k4;		       // temp space to hold f(x,t) output
};



#endif // RUNGE-KUTTA_H_
