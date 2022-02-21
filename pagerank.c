#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "matrices.h"
#include "tableaux.h"
#include "ggraphe.h"

void pagerank(char* nom_fichier);
t_matrice liste_to_matrice_transition(t_liste_adjacence* liste);
int comparer_flottants (const void * a, const void * b);

int main(int argc, char const *argv[])
{
    pagerank("data/p2p-Gnutella25.txt");
    return 0;
}

void pagerank(char* nom_fichier){
    clock_t depart,duree;
    int milisecondes;
    t_liste_adjacence liste = lire_liste_adjacence(nom_fichier);
    milisecondes = duree * 1000 / CLOCKS_PER_SEC;
    trier_liste_adjacence(&liste);
    t_matrice m = liste_to_matrice_transition(&liste);
    liberer_liste_adjacence(liste);
    t_matrice prod;
    t_matrice r = matrice_uniforme(1,1,1);
    float jump;
    int i;
    float damping = 0.85;
    float epsilon;
    for(epsilon = 1; epsilon > 0.00000000001; epsilon *= 0.1){
        jump = (float)((1-damping)/m.hauteur);
        prod = matrice_uniforme(m.hauteur, 1, (float)1/m.hauteur);
        depart = clock();
        i = 0;
        do{
            vider_matrice(r);
            r = copie_matrice(prod);
            vider_matrice(prod);
            prod = produit_matriciel(m,r);
            produit_matrice_float_en_place(&prod, damping);
            somme_matrice_float_en_place(&prod, jump);
            i++;
        }while(norme_diff_vecteur(prod,r) > epsilon);
        duree = clock() - depart;
        milisecondes = duree * 1000 / CLOCKS_PER_SEC;
        printf("%.10f;%d,%d;%d\n", epsilon,milisecondes/1000,milisecondes%1000,i);
        vider_matrice(prod);
    }
    //afficher_matrice(prod);
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
            //printf("on écrit %f dans la case(%d,%d)\n",(float)1/nb_dest,liste->noeud[i].dest[j],id);
            matrice.tableau[liste->noeud[i].dest[j]][id] = (float)1/nb_dest;
        }
    }
    return matrice;
}

int comparer_flottants (const void * a, const void * b) {
   float comp = ( *(float*)a - *(float*)b );
   int ret;
   if(comp > 0){
       ret = 1;
   }else if(comp == 0){
       ret = 0;
   }else{
       ret = -1;
   }
   return ret;
}