#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"
#include "tableaux.h"

void pagerank();

int main(int argc, char const *argv[])
{
    t_matrice matrice1 = lire_matrice();
    t_matrice matrice2 = matrice_uniforme(5,1,(float)1/5);
    t_matrice produit = produit_matriciel(matrice1,matrice2);
    afficher_matrice(produit);
    vider_matrice(matrice1);
    vider_matrice(matrice2);
    vider_matrice(produit);
    return 0;
}

void pagerank(int n){
    t_matrice r = matrice_uniforme(n, 1, (float)1/n);
    afficher_matrice(r);
    vider_matrice(r);
}