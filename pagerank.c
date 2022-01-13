#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"
#include "tableaux.h"

void pagerank();

int main(int argc, char const *argv[])
{
    pagerank(5);
    return 0;
}

void pagerank(int n){
    t_matrice m = lire_matrice();
    t_matrice r = matrice_uniforme(n, 1, (float)1/n);
    t_matrice prod;
    for(int i = 0; i < 100; i++){
        prod = produit_matriciel(m,r);
        vider_matrice(r);
        r = prod;
    }
    afficher_matrice(r);
    vider_matrice(r);
}