#include "copy.c"
#include <stdio.h>

int main()
{
    // ------------ test fonction scopy --------------- 
    //float Xf[10] = {0,1,2,3,4,5,6,7,8,9};
    float Xfbis[20] = {0,1,2,3,4,5,6,7,8,9,20,21,22,23,24,25,26,27,28,29};
    float Yf[10] = {10,11,12,13,14,15,16,17,18,19};


    //mncblas_scopy(10,Xf,1,Yf,1);
    for (int i = 0; i < 10; i++)
    {
        //printf("Valeur %d : %lf \n", i, Xf[i]);
        //printf("Valeur %d : %lf \n", i, Yf[i]);
    }

    mncblas_scopy(10,Xfbis,2,Yf,1);
    for (int i = 0; i < 10; i++)
    {
        //printf("Valeur %d : %lf \n", i, Xfbis[i*2]);
        //printf("Valeur %d : %lf \n", i, Yf[i]);
    }

    /* affiche  Valeur 0 : 0.000000 
                Valeur 0 : 0.000000 
                Valeur 1 : 2.000000 
                Valeur 1 : 2.000000 
                Valeur 2 : 4.000000 
                Valeur 2 : 4.000000 
                Valeur 3 : 6.000000 
                Valeur 3 : 6.000000 
                Valeur 4 : 8.000000 
                Valeur 4 : 8.000000 
                Valeur 5 : 20.000000 
                Valeur 5 : 15.000000 
                Valeur 6 : 22.000000 
                Valeur 6 : 16.000000 
                Valeur 7 : 24.000000 
                Valeur 7 : 17.000000 
                Valeur 8 : 26.000000 
                Valeur 8 : 18.000000 
                Valeur 9 : 28.000000 
                Valeur 9 : 19.000000 
    -> problème ?
    */

    printf("voir test scopy avec une incrémentation de 2 \n");

    // ------------ test fonction dcopy --------------- 
    double Xd[10] = {0,1,2,3,4,5,6,7,8,9};
    double Yd[10] = {10,11,12,13,14,15,16,17,18,19};

    mncblas_dcopy(10,Xd,1,Yd,1);
    for (int i = 0; i < 10; i++)
    {
        //printf("Valeur %d : %lf \n", i, Xd[i]);
        //printf("Valeur %d : %lf \n", i, Yd[i]);
    }

    // ------------ test fonction ccopy --------------- 
                         
    complexe_float_t c1= (complexe_float_t){1.0, 1.0} ;
    complexe_float_t c2= (complexe_float_t){2.0, 2.0} ;
    complexe_float_t c3= (complexe_float_t){3.0, 4.0} ;
    
    complexe_float_t Xc[3] = {c1, c2, c3};
    complexe_float_t Yc[3] = {c3, c2, c1};

    mncblas_ccopy(3,Xc,1,Yc,1);
    for (int i = 0; i < 3; i++)
    {
        //printf("Valeur %d : %lf, %lf \n", i,  Xc[i].real, Xc[i].imaginary);
        //printf("Valeur %d : %lf, %lf \n", i,  Yc[i].real, Yc[i].imaginary);

    }

    // ------------ test fonction zcopy --------------- 
                          
    complexe_double_t z1=  (complexe_double_t) {1.0, 2.0} ;
    complexe_double_t z2= (complexe_double_t) {3.0, 4.0} ;
    complexe_double_t z3= (complexe_double_t) {5.0, 6.0} ;
    
    complexe_double_t Xz[3] = {z1, z2, z3};
    complexe_double_t Yz[3] = {z3, z2, z1};


    mncblas_zcopy(3,Xz,1,Yz,1);
    for (int i = 0; i < 3; i++)
    {
        //printf("Valeur %d : %lf, %lf \n", i, Xz[i].real, Xz[i].imaginary);
        //printf("Valeur %d : %lf, %lf \n", i, Yz[i].real, Yz[i].imaginary);
    }




   
    return 0;

}