#include "euler.h"
#include "model.h"
// We include "model.h" b/c the initializer list of Euler's ctor and
// the body of Step both use methods of Model, so the compiler needs
// to know which methods Model does/doesn't have. All of that is
// specified in the "model.h" header.

Euler::Euler(double dt, const Model &model)
   : dimen_(model.dimen()), 	//
     dt_(dt),			// Initializer list
     model_(model)		//
{
   // Constructor allocates memory to hold output of f(x,t)...
   fx_ = new double[dimen_];
}

Euler::~Euler()
{
   // ...so destructor must free that memory before Euler instance
   // itself is freed.
   delete [] fx_;
}

int Euler::Step(double t, double *x)
{
   model_.rhs(t, x, fx_);
   for (int i = 0; i < dimen_; ++i)
   {
      x[i] += dt_ * fx_[i];
   }

   return 0;
}
