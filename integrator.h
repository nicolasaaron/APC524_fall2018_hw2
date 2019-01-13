#ifndef INTEGRATOR_H_
#define INTEGRATOR_H_

// ABC for an object that integrates first-order ODEs
class Integrator
{
public:
   virtual ~Integrator() {}
   virtual int Step(double t, double *x) = 0;
  // The "= 0" above is just syntax to indicate that this method is
  // "pure virtual"; including at least one pure virtual method is the
  // C++ way of making a class formally an ABC (so that it cannot be
  // directly instantiated).

};

#endif  // INTEGRATOR_H_
