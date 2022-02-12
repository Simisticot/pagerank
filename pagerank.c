#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrices.h"
#include "tableaux.h"
#include "ggraphe.h"

void pagerank(double epsilon, char* nom_fichier);
t_matrice liste_to_matrice_transition(t_liste_adjacence* liste);

int main(int argc, char const *argv[])
{
    pagerank(0.01, "email.txt");
    return 0;
}

void pagerank(double epsilon, char* nom_fichier){
    t_liste_adjacence liste = lire_liste_adjacence(nom_fichier);
    trier_liste_adjacence(&liste);
    t_matrice m = liste_to_matrice_transition(&liste);
    t_matrice prod = matrice_uniforme(m.hauteur, 1, (float)1/m.hauteur);
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
    liberer_liste_adjacence(liste);
}

t_matrice liste_to_matrice_transition(t_liste_adjacence* liste){
    int fin = liste->noeud[liste->longueur-1].id;
    int nb_dest,id;
    t_matrice matrice = matrice_uniforme(fin+1, fin+1, 0);
    for(int i = 0; i < liste->longueur; i++){
        nb_dest = liste->noeud[i].nb_dest;
        id = liste->noeud[i].id;
        for(int j = 0; j < nb_dest; j++){
            //printf("on écrit %f dans la case(%d,%d)\n",(float)1/nb_dest,liste->noeud[i].dest[j],id);
            matrice.tableau[liste->noeud[i].dest[j]][id] = (float)1/nb_dest;
        }
    }
    return matrice;
}
