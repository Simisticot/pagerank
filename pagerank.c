#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrices.h"
#include "tableaux.h"
#include "ggraphe.h"

void pagerank(int n, double epsilon);
t_matrice liste_to_matrice_transition(t_liste_adjacence* liste);

int main(int argc, char const *argv[])
{
    t_liste_adjacence liste = lire_liste_adjacence("email.txt");
    trier_liste_adjacence(&liste);
    // afficher_liste_adjacence(liste);
    // printf("La liste est de longueur : %d\n", liste.longueur);
    t_matrice transition = liste_to_matrice_transition(&liste);
    //afficher_matrice(transition);
    vider_matrice(transition);
    liberer_liste_adjacence(liste);
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

t_matrice liste_to_matrice_transition(t_liste_adjacence* liste){
    int fin = liste->noeud[liste->longueur-1].id;
    int nb_dest,id;
    t_matrice matrice = matrice_uniforme(fin+1, fin+1, 0);
    for(int i = 0; i < liste->longueur; i++){
        nb_dest = liste->noeud[i].nb_dest;
        id = liste->noeud[i].id;
        for(int j = 0; j < nb_dest; j++){
            matrice.tableau[liste->noeud[i].dest[j]][id] = (float)1/nb_dest;
        }
    }
    return matrice;
}
