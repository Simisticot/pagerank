#include <stdio.h>
#include "matrices.h"
#include "tableaux.h"

int main(int argc, char const *argv[])
{
    //J'y crois
    printf("Je me bas un peu avec git\n");
    t_matrice zerou = matrice_zero(10, 10);
    afficher_matrice(zerou);
    vider_matrice(zerou);
    return 0;
}