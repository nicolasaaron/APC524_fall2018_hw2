#include "adams-bashforth.h"

#include "model.h"
// We include "model.h" b/c the initializer list of Adams-bashforth's
// constructor and the body of Step both use methods of Model,
// so the compiler needs to know which methods Model does/doesn't have.
// All of that is specified in the "model.h" header.

AdamsBashforth::AdamsBashforth(double dt, const Model &model, Integrator *first_integrator)
   : dimen_(model.dimen()), 	//
     dt_(dt),			// Initializer list
     model_(model),		//
     first_step_integrator_(first_integrator)
{
   // Constructor allocates memory to hold output of f(x,t)...
   fx_ = new double[dimen_];
   prev_fx_ = new double[dimen_];
}

AdamsBashforth::~AdamsBashforth()
{
   // ...so destructor must free that memory before Euler instance
   // itself is freed.
   delete [] fx_;
   delete [] prev_fx_;
   delete first_step_integrator_;
}

int AdamsBashforth::Step(double t, double *x)
{
   static bool first_step = true;

   if (first_step)
   {
        first_step=false;
        model_.rhs(t,x,prev_fx_);
        first_step_integrator_-> Step(t,x);
   }
   else{
        model_.rhs(t, x, fx_);
        for (int i = 0; i < dimen_; ++i)
        {
              x[i] += 1.5 * dt_ * fx_[i] - 0.5 * dt_ * prev_fx_[i] ;
              prev_fx_[i] = fx_[i];
        }
   }

   return 0;
}
