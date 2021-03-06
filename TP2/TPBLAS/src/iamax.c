#include "mnblas.h"
#include "complexe.h"
#include <stdio.h>
#include <math.h>

//Computes the global index of the element of a distributed vector with maximum absolute value.

int mnblas_isamax(const int N, const float *X, const int incX)
{
  //done
  register unsigned int i = 0 ;
  float max = X[0] ;
  int index = 0 ;
  
  for (i = 1 ; i < N ; i += incX)
    {
      if (X[i]>max){
      	max = X[i];
      	index = i;
      }
 
    }

  return index;
}

int mnblas_idamax(const int N, const double *X, const int incX)
{
  //done
  register unsigned int i = 0 ;
  double max = X[0] ;
  int index = 0 ;
  
  for (i = 1 ; i < N ; i += incX)
    {
      if (X[i]>max){
      	max = X[i];
      	index = i;
      }
 
    }

  return index;
}

int mnblas_icamax(const int N, const void *X, const int incX)
{
  //done
  register unsigned int i = 0 ;
  float max = pow( (((complexe_float_t*)X)[0].real) * (((complexe_float_t*)X)[0].real) + (((complexe_float_t*)X)[0].imaginary) * (((complexe_float_t*)X)[0].imaginary), 0.5 );
  int index = 0 ;

  for (i = 1 ; i < N ; i += incX)
    {
      float len = pow( (((complexe_float_t*)X)[i].real) * (((complexe_float_t*)X)[i].real) + (((complexe_float_t*)X)[i].imaginary) * (((complexe_float_t*)X)[i].imaginary), 0.5 );
      if (len > max)
      {
        max = len;
        index = i;
      }
 
    }

  return index;
}

int mnblas_izamax(const int N, const void *X, const int incX)
{
   //done
  register unsigned int i = 0 ;
  float max = pow( (((complexe_double_t*)X)[0].real) * (((complexe_double_t*)X)[0].real) + (((complexe_double_t*)X)[0].imaginary) * (((complexe_double_t*)X)[0].imaginary), 0.5 );
  int index = 0 ;

  for (i = 1 ; i < N ; i += incX)
    {
      double len = pow( (((complexe_double_t*)X)[i].real) * (((complexe_double_t*)X)[i].real) + (((complexe_double_t*)X)[i].imaginary) * (((complexe_double_t*)X)[i].imaginary), 0.5 );
      if (len > max)
      {
        max = len;
        index = i;
      }
 
    }

  return index;

 
}