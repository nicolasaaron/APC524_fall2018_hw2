#ifndef LINEAR_OSCILLATOR_H_
#define LINEAR_OSCILLATOR_H_

#include "model.h"
// Here, we must include the whole "model.h" header b/c linear oscillator is a
// subclass of Model. Consequently, the compiler needs to furnish
// Linear Oscillator with all the internal structure of Model (since every
// instance of Linear Oscillator is also, by necessity, an instance of Model,
// with everything that entails). And the internal layout of Model is
// specified in "model.h".


// Linear oscillator:
//   \dot x = y
//   \dot y = -x - 2*beta*y -  gamma * cos(omega t)
class LinearOscillator : public Model
{
public:
   LinearOscillator(double beta, double gamma, double omega);
   ~LinearOscillator();

   int rhs(double t, const double *x, double *fx) const;

   // this function is inlined for speed
   int dimen() const { return kDimen_; }

private:
   // All instances of this class have kDimen_ == 2
   static const int kDimen_ = 2;
   const double beta_;
   const double gamma_;
   const double omega_;
};

#endif // LINEAR_OSCILLATOR_H_
