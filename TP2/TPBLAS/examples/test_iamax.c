#include <stdio.h>
#include "mnblas.h"
#include "complexe.h"
#include "flop.h"

#define VECSIZE    65536
#define NB_FOIS    10
typedef float vfloat [VECSIZE] ;
typedef double vdouble [VECSIZE];
typedef complexe_double_t vcomplexe_double_t [VECSIZE];
typedef complexe_float_t vcomplexe_float_t [VECSIZE];

vfloat vfloat1;
vdouble vdouble1;
vcomplexe_double_t vcomplexedouble1;
vcomplexe_float_t vcomplexefloat1;

/*
int mncblas_samax(const int N, const float *X, const int incX, void* maximum)
int mncblas_damax(const int N, const double *X, const int incX, void* maximum)
int mncblas_camax(const int N, const void *X, const int incX, void* maximum)
int mncblas_zamax(const int N, const void *X, const int incX, void* maximum)
*/


int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 int res = 0;
 void* max;
/*
 * 
 * 
 * Tests fonction mncblas_samax (avec des float)
 * 
 * 
 */

 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
           vfloat1[i] = 3.0+i;
       }
     start_tsc = _rdtsc () ;
        res = mncblas_samax (VECSIZE, vfloat1, (const int)1, max);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_samax nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("max at index index %d : %f\n", res, *((float*)max));
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vfloat1[i] = 3.0+i;
        }
     
     TOP_MICRO(start) ;
        res = mncblas_samax (VECSIZE, vfloat1, (const int)1, max);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_samax micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("max at index index %d : %f\n", res, *((float*)max));
 printf ("==========================================================\n") ;



/*
 * 
 * 
 * Tests fonction mncblas_damax (avec des double)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
           vdouble1[i] = 3.0+i;
       }
    
     start_tsc = _rdtsc () ;
        res = mncblas_damax (VECSIZE, vdouble1,(const int)1, max);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_damax nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("max at index index %d : %lf\n", res, *((double*)max));
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vdouble1[i] = 3.0+i;
        }
     
     TOP_MICRO(start) ;
        res = mncblas_damax (VECSIZE, vdouble1, (const int)1, max);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_damax micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("max at index index %d : %lf\n", res, *((double*)max));
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mncblas_camax (avec des complexe_float_t)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexefloat1[i] = (complexe_float_t){3.0+i,4.5+i};
       }
     res = 0.0 ;
    
     start_tsc = _rdtsc () ;
        res = mncblas_camax (VECSIZE, vcomplexefloat1, (const int)1, max) ;
     end_tsc = _rdtsc ();
     
     calcul_flop_tsc ("mncblas_camax nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("max at index index %d : (%f, %f)\n", res, ((complexe_float_t*)max)->real,((complexe_float_t*)max)->imaginary );
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexefloat1[i] = (complexe_float_t){3.0+i,4.5+i};
       }
     
     TOP_MICRO(start) ;
        res = mncblas_camax (VECSIZE, vcomplexefloat1, (const int)1, max) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_camax micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("max at index index %d : (%f, %f)\n", res, ((complexe_float_t*)max)->real,((complexe_float_t*)max)->imaginary );
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mncblas_zamax (avec des complexe_double_t)
 * 
 * 
 */
 init_flop_tsc () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0+i,4.5+i};
       }
    
     start_tsc = _rdtsc () ;
        res = mncblas_zamax (VECSIZE, vcomplexedouble1, (const int)1, max) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mncblas_zamax nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("max at index index %d : (%lf, %lf)\n", res, ((complexe_double_t*)max)->real,((complexe_double_t*)max)->imaginary );
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0+i,4.5+i};
       }
     
     TOP_MICRO(start) ;
        res = mncblas_zamax (VECSIZE, vcomplexedouble1, (const int)1, max);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mncblas_zamax micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("max at index index %d : (%lf, %lf)\n", res, ((complexe_double_t*)max)->real,((complexe_double_t*)max)->imaginary );
 printf ("==========================================================\n") ;

}