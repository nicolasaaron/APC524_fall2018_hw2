#ifndef ADAMS_BASHFORTH_H_
#define ADAMS_BASHFORTH_H_

#include "integrator.h"
class Model;                   // Forward declaration
// Above is better than include-ing "model.h" b/c the Euler class
// doesn't need to know anything about how Model works, just that
// there is a data type (i.e. a class) called "Model"

// Fixed-timestep Euler integrator
class AdamsBashforth : public Integrator
{
public:
   AdamsBashforth(double dt,const Model &model, Integrator *first_integrator);
   ~AdamsBashforth();

   int Step(double t, double *x);

private:
   const double dt_;	       // integration timestep

   const Model &model_;	       // object w/ info about ODE system,
			       // including dimension of state vector
			       // and function f(x,t) for evaluating
			       // derivative of the state vector
   Integrator *first_step_integrator_; // integrator used to compute the first time step

   const int dimen_;           // dimension of state vector x
   double *fx_;                 // temp space to hold f(x_j,t_j) output
   double *prev_fx_;		       // temp space to hold the previous step f(x_{j-1},t_{j-1}) output
};

#endif // ADAMS_BASHFORTH_H_
