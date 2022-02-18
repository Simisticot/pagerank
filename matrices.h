#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tableaux.h"

typedef struct t_matrice{
	int hauteur;
	int largeur;
	float** tableau;
} t_matrice;

t_matrice creer_matrice(int hauteur, int largeur);
t_matrice matrice_uniforme(int hauteur, int largeur, float valeur);
t_matrice remplir_matrice(t_matrice matrice);
void afficher_matrice(t_matrice matrice);
t_matrice produit_matriciel(t_matrice matrice1, t_matrice matrice2);
void vider_matrice(t_matrice matrice);
t_matrice lire_matrice();
double norme_vecteur(t_matrice vecteur);
t_matrice somme_matricielle(t_matrice a, t_matrice b);
t_matrice difference_matricielle(t_matrice a, t_matrice b);
double norme_diff_vecteur(t_matrice a, t_matrice b);
t_matrice copie_matrice(t_matrice a);
void somme_matrice_float_en_place(t_matrice* a, float b);
void produit_matrice_float_en_place(t_matrice* a, float b);