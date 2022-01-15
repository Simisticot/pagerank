#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrices.h"
#include "tableaux.h"

void pagerank();

int main(int argc, char const *argv[])
{
    pagerank(5,0.001);
    return 0;
}

void pagerank(int n, double epsilon){
    t_matrice m = lire_matrice();
    t_matrice prod = matrice_uniforme(n, 1, (float)1/n);
    t_matrice r = matrice_uniforme(1,1,1);
    do{
        vider_matrice(r);
        r = copie_matrice(prod);
        vider_matrice(prod);
        prod = produit_matriciel(m,r);
    }while(norme_diff_vecteur(prod,r) > epsilon);
    afficher_matrice(prod);
    vider_matrice(prod);
    vider_matrice(r);
    vider_matrice(m);
}