#include "optimizer.hpp"

UserFunction::UserFunction(){}

UserFunction::~UserFunction(){}


Optimizer::Optimizer()
{
   objective = 0.0;
   gnorm     = 0.0;
   maxiter   = 0;
   hessian   = NULL;

}

Optimizer::~Optimizer(){}

void Optimizer::initialize(UserFunction  *Function,
                           HessianApprox *Hessian, 
                           int            DimN,
                           int            maxIter)
{
   dimN    = DimN;
   maxiter = maxIter;

   hessian  = Hessian;
   function = Function;
}


void Optimizer::run()
{
   for (int iter = 0; iter < maxiter; iter++)
   {
      /* evaluate objective */

      /* evaluate gradient and its norm */

      /* Output */

      /* Optimization control */

      /* Design update */
   }
}


