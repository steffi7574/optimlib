#include "hessianApprox.hpp"
#include "defs.hpp"

#pragma once

/*************************************************************
 * Interface
 *************************************************************/

/* 
 * Abstract base class for user-defined function 
 * Inherit from it and implement the virtual functions
 */
class UserFunction  
{
   
   public:
      UserFunction();
      ~UserFunction();

      /* Reaturn the objective function value f(x) */
      virtual MyReal evaluateObjective(MyReal* x) = 0;  

      /* Compute the gradient \nabla f(x) and return it's norm */
      virtual MyReal evaluateGradient(MyReal* x, MyReal* gradient)  = 0;

      virtual void callMeOncePerIter();
};


/*****************************************************************
 * Optimizer
 ****************************************************************/

/* Optimization class */
class Optimizer 
{
   private:
      MyReal  objective;             /* Objective function value */
      MyReal  gnorm;                 /* Norm of the gradient */
      MyReal* design;                /* Pointer to the design variable */
      MyReal* gradient;              /* Pointer to the gradient variable */

   protected:

      int dimN;
      int maxiter;                  /* Maximum number of optimization iterations */

      HessianApprox* hessian;       /* Hessian approximation */
      UserFunction*  function;      /* User-defined function that is to be minimized */

   public:

      Optimizer();
      ~Optimizer();

      void initialize(UserFunction  *Function,
                      HessianApprox *Hessian, 
                      MyReal        *design_ptr,
                      MyReal        *gradient_ptr,
                      int            DimN,
                      int            maxIter);

      void run();
};

