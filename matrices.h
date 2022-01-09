#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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