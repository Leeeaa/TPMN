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
int mnblas_isamax(const int N, const float *X, const int incX, void* maximum)
int mnblas_idamax(const int N, const double *X, const int incX, void* maximum)
int mnblas_icamax(const int N, const void *X, const int incX, void* maximum)
int mnblas_izamax(const int N, const void *X, const int incX, void* maximum)
*/


int main (int argc, char **argv)
{
 struct timeval start, end ;
 unsigned long long int start_tsc, end_tsc ;
 int res = 0;
/*
 * 
 * 
 * Tests fonction mnblas_isamax (avec des float)
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
        res = mnblas_isamax (VECSIZE, vfloat1, (const int)1);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_isamax nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("max at index index %d\n", res);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vfloat1[i] = 3.0+i;
        }
     
     TOP_MICRO(start) ;
        res = mnblas_isamax (VECSIZE, vfloat1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_isamax micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("max at index index %d\n", res);
 printf ("==========================================================\n") ;



/*
 * 
 * 
 * Tests fonction mnblas_idamax (avec des double)
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
        res = mnblas_idamax (VECSIZE, vdouble1,(const int)1);
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_idamax nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
 printf ("max at index index %d\n", res);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
        for (int j = 0; j < VECSIZE; j++)
        {
            vdouble1[i] = 3.0+i;
        }
     
     TOP_MICRO(start) ;
        res = mnblas_idamax (VECSIZE, vdouble1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_idamax micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("max at index index %d\n", res);
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mnblas_icamax (avec des complexe_float_t)
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
        res = mnblas_icamax (VECSIZE, vcomplexefloat1, (const int)1) ;
     end_tsc = _rdtsc ();
     
     calcul_flop_tsc ("mnblas_icamax nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("max at index index %d\n", res);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
      for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexefloat1[i] = (complexe_float_t){3.0+i,4.5+i};
       }
     
     TOP_MICRO(start) ;
        res = mnblas_icamax (VECSIZE, vcomplexefloat1, (const int)1) ;
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_icamax micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
printf ("max at index index %d\n", res);
 printf ("==========================================================\n") ;


/*
 * 
 * 
 * Tests fonction mnblas_izamax (avec des complexe_double_t)
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
        res = mnblas_izamax (VECSIZE, vcomplexedouble1, (const int)1) ;
     end_tsc = _rdtsc () ;
     
     calcul_flop_tsc ("mnblas_izamax nano ", 2 * VECSIZE, end_tsc-start_tsc) ;
   }
printf ("max at index index %d\n", res);
 printf ("==========================================================\n") ;
 
 init_flop_micro () ;
 for (int i = 0 ; i < NB_FOIS; i++)
   {
       for (int i = 0; i < VECSIZE; i++)
       {
            vcomplexedouble1[i] = (complexe_double_t){3.0+i,4.5+i};
       }
     
     TOP_MICRO(start) ;
        res = mnblas_izamax (VECSIZE, vcomplexedouble1, (const int)1);
     TOP_MICRO(end) ;
     
     calcul_flop_micro ("mnblas_izamax micro", 2 * VECSIZE, tdiff_micro (&start, &end)) ;
   }
 printf ("max at index index %d\n", res);
 printf ("==========================================================\n") ;

}