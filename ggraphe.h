#include <stdio.h>

typedef struct t_noeud{
	int id;
	int nb_dest;
	int* dest;
} t_noeud;

typedef struct t_liste_adjacence{
	int longueur;
	t_noeud* noeud;
} t_liste_adjacence;

void direbjr();
t_noeud initialiser_noeud(int identifiant, int premier_voisin);
void ajouter_voisin(t_noeud noeud, int nouveau_voisin);
void liberer_noeud(t_noeud noeud);
void afficher_noeud(t_noeud noeud);
t_liste_adjacence initialiser_liste_adjacence();
void ajouter_noeud(t_liste_adjacence* liste, t_noeud nouveau_noeud);
void liberer_liste_adjacence(t_liste_adjacence liste);
void afficher_liste_adjacence(t_liste_adjacence liste);
int index_noeud(t_liste_adjacence liste, int id);
t_liste_adjacence lire_liste_adjacence(char* nom_fichier);
