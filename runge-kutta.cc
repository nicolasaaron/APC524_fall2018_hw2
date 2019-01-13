#include "runge-kutta.h"
#include "model.h"
// We include "model.h" b/c the initializer list of runge-kutta's constructor and
// the body of Step both use methods of Model, so the compiler needs
// to know which methods Model does/doesn't have. All of that is
// specified in the "model.h" header.

RungeKutta4::RungeKutta4(double dt, const Model &model)
   : dimen_(model.dimen()), 	//
     dt_(dt),			// Initializer list
     model_(model)		//
{
   // Constructor allocates memory to hold output of f(x,t)...
   k1 = new double[dimen_];
   k2 = new double[dimen_];
   k3 = new double[dimen_];
   k4 = new double[dimen_];

}

RungeKutta4::~RungeKutta4()
{
   // ...so destructor must free that memory before Euler instance
   // itself is freed.
   delete [] k1;
   delete [] k2;
   delete [] k3;
   delete [] k4;
}

int RungeKutta4::Step(double t, double *x)
{
   double h = dt_;
   double *x2 = new double[dimen_];
   double *x3 = new double[dimen_];
   double *x4 = new double[dimen_];

    //update k1
   model_.rhs(t, x, k1);
   for (int i = 0; i < dimen_; ++i)
   {
      x2[i] = x[i] + h/2 * k1[i];
   }

    //update k2
   model_.rhs(t+ h/2, x2, k2);
   for (int i =0; i< dimen_; ++i)
   {
       x3[i] = x[i] + h/2 * k2[i];
   }

   //update k3
   model_.rhs(t+h/2, x3, k3);
   for (int i=0; i< dimen_; ++i)
   {
       x4[i] = x[i] + h * k3[i];
   }

   //update k4
   model_.rhs(t+h, x4, k4);

   //update x_j to x_{j+1}
   for (int i=0; i< dimen_; ++i)
   {
       x[i] += h/6 * k1[i] + h/3 * (k2[i] + k3[i]) + h/6 * k4[i];
   }

   delete [] x2;
   delete [] x3;
   delete [] x4;
   return 0;
}
