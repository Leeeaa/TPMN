#include <stdio.h>
#include <stdlib.h>

#include "poly.h"

#include <x86intrin.h>


//on utilise 2 tableaux non triés


p_polyf_creux_t creer_polynome (int nbMonome)
{
  p_polyf_creux_t p = (p_polyf_creux_t) malloc (sizeof (polyf_creux_t)) ;
  p->nbMonome = nbMonome ;
  p->coeff = (float *) malloc (nbMonome * sizeof (float))  ;
  p->degre = (int *) malloc (nbMonome * sizeof (int)) ;
  return p ;
}

void detruire_polynome (p_polyf_creux_t p)
{
  free (p->coeff) ;
  free (p->degre) ;
  free (p) ;
  return ;
}


void init_polynome (p_polyf_creux_t p, float x)
{
  if(x == 0 && p->nbMonome != 0) {
    free(p->coeff);
    free(p->degre);
    p->nbMonome = 0;
  } else {
    for (int i = 0 ; i < p->nbMonome; ++i)
      p->coeff [i] = x ;
  }
  return ;
}



p_polyf_creux_t lire_polynome_float (char *nom_fichier)
{
  FILE *f ;
  p_polyf_creux_t p ;
  int nbMonome ;
  int i  ;
  int cr ;
  
  f = fopen (nom_fichier, "r") ;
  if (f == NULL)
    {
      fprintf (stderr, "erreur ouverture %s \n", nom_fichier) ;
      exit (-1) ;
    }
  
  cr = fscanf (f, "%d", &nbMonome) ;
  if (cr != 1)
    {
      fprintf (stderr, "erreur lecture du nombre de monome\n") ;
      exit (-1) ;
    }
  p = creer_polynome (nbMonome) ;
  
  for (i = 0 ; i < nbMonome; i++)
    { 
      cr = fscanf (f, "%d %f",&(p->degre[i]), &(p->coeff[i])) ;
      if (cr != 2)
      {
        fprintf (stderr, "erreur lecture coefficient ou degre %d ieme / %d\n", i, p->nbMonome) ;
        exit (-1) ;
      }
       
    }

  fclose (f) ;

  return p ;
}



void ecrire_monome(p_polyf_creux_t p, int i) {
  if(i < p->nbMonome) {
    if(p->degre[i] == 0) {
      printf("%f", p->coeff[i]);
    } else if(p->degre[i] == 1) {
      printf("%f X", p->coeff[i]);
    } else {
      printf ("%f X^%d", p->coeff [i], p->degre[i]) ;
    }
  }
}


void ecrire_polynome_float (p_polyf_creux_t p)
{
  if(p->nbMonome >= 1) {
    ecrire_monome(p,0);
  }
  for (int i = 1 ; i < p->nbMonome; i++)
    {  
      printf(" + ");
      ecrire_monome(p,i);
    }
  printf ("\n") ;
  return ;
}


int contient_int(int nb, int* tab, int len) {
  if(tab != NULL) {
    for(int i = 0; i < len ; i++) {
      if(tab[i] == nb) {
        return i;
      }
    }
  }
  return -1;
}


int egalite_polynome (p_polyf_creux_t p1, p_polyf_creux_t p2)
{
  if(p1->nbMonome == p2->nbMonome) {
    return 0;
  }
  for(int i = 0; i < p1->nbMonome; i++) {
    int tmp = contient_int(p1->degre[i],p2->degre,p2->nbMonome);
    if (tmp == -1 ||p1->coeff[tmp] != p2->coeff[tmp]){
      return 0;
    }
  }

  return 1 ;
}

void inserer_monome(p_polyf_creux_t p, float coeff, int degre) {
  if(p->nbMonome == 0) {
    p->nbMonome++;
    p->coeff = (float *) malloc (p->nbMonome * sizeof (float))  ;
    p->degre = (int *) malloc (p->nbMonome * sizeof (int)) ;
  } else {
    p->nbMonome++;
    float* tmp = p->coeff;
    int* tmp2 = p->degre;
    p->coeff = (float *) malloc (p->nbMonome * sizeof (float))  ;
    p->degre = (int *) malloc (p->nbMonome * sizeof (int)) ;
    for(int i = 0; i < p->nbMonome-1 ; i++) {
      p->coeff[i] = tmp[i];
      p->degre[i] = tmp2[i];
    }
    free(tmp);
    free(tmp2);
  }
  p->coeff[p->nbMonome-1] = coeff;
  p->degre[p->nbMonome-1] = degre;
}


p_polyf_creux_t addition_polynome (p_polyf_creux_t p1, p_polyf_creux_t p2)
{
  p_polyf_creux_t p3 ;
  
  p3 = creer_polynome (p1->nbMonome);
  for(int i = 0; i < p1->nbMonome ; i++) {
    p3->coeff[i] = p1->coeff[i];
    p3->degre[i] = p1->degre[i];
  }
  for(int i = 0; i < p2->nbMonome ; i++) {
    int tmp = contient_int(p2->degre[i],p3->degre,p3->nbMonome);
    if(tmp != -1) {
      p3->coeff[tmp] += p2->coeff[i];
    } else {
      inserer_monome(p3,p2->coeff[i],p2->degre[i]);
    }
  }
  return p3 ;
}


p_polyf_creux_t multiplication_polynome_scalaire (p_polyf_creux_t p, float alpha)
{
  p_polyf_creux_t p_result = creer_polynome(p->nbMonome);
  for(int i = 0; i < p->nbMonome ; i++) {
    p_result->coeff[i] = p->coeff[i] * alpha;
  }
  return p_result ;
}


float puiss_float (float x, int deg) {
	float result = 1.0;

	for (int i = 0; i < deg; i++)
		result *= x;

	return result;
}


float eval_polynome (p_polyf_creux_t p, float x)
{
  float result = 0;
  for(int i = 0; i < p->nbMonome; i++) {
    result += p->coeff[i] * puiss_float(x,p->degre[i]);
  }
  return result;
}

