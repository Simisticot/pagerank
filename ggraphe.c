#include <stdio.h>
#include <stdlib.h>
#include "ggraphe.h"


void direbjr(){
	printf("coucou");
}

t_noeud initialiser_noeud(int identifiant, int premier_voisin){
	t_noeud noeud;
	noeud.nb_dest = 1;
	noeud.id = identifiant;
	noeud.dest = (int*)malloc(sizeof(int));
	noeud.dest[0] = premier_voisin;
	return noeud;
}

void ajouter_voisin(t_noeud noeud, int nouveau_voisin){
	noeud.nb_dest++;
	noeud.dest = (int*)realloc(noeud.dest, sizeof(int)*noeud.nb_dest);
	noeud.dest[noeud.nb_dest-1];
}

void liberer_noeud(t_noeud noeud){
	free(noeud.dest);
}

void afficher_noeud(t_noeud noeud){
	printf("%d ->",noeud.id);
	for(int i = 0; i < noeud.nb_dest; i++){
		printf(" %d", noeud.dest[i]);
	}
	printf("\n");
}

t_liste_adjacence initialiser_liste_adjacence(){
	t_liste_adjacence liste;
	liste.longueur = 0;
	liste.noeud = malloc(0);
	return liste;
}

void ajouter_noeud(t_liste_adjacence* liste, t_noeud nouveau_noeud){
	liste->longueur++;
	liste->noeud = (t_noeud*)realloc(liste->noeud, sizeof(t_noeud)*liste->longueur);
	liste->noeud[liste->longueur-1] = nouveau_noeud;
}

void liberer_liste_adjacence(t_liste_adjacence liste){
	for(int i = 0; i < liste.longueur; i++){
		liberer_noeud(liste.noeud[i]);
	}
	free(liste.noeud);
}

void afficher_liste_adjacence(t_liste_adjacence liste){
	for(int i = 0; i < liste.longueur; i++){
		afficher_noeud(liste.noeud[i]);
	}
}

int index_noeud(t_liste_adjacence liste, int id){
	int index = -1;
	for(int i = 0; i < liste.longueur; i++){
		if(liste.noeud[i].id == id){
			index = i;
			break;
		}
	}
	return index;
}

t_liste_adjacence lire_liste_adjacence(char* nom_fichier){
	FILE* fichier;
	fichier = fopen(nom_fichier, "r");
	int a,b,c;
	int index;
	t_noeud nouveau;
	t_liste_adjacence liste = initialiser_liste_adjacence();
	while(fscanf(fichier, "%d %d %d\n", &a, &b, &c)==3){
		index = index_noeud(liste, a);
		if(index >= 0){
			printf("ajout voisin\n");
			ajouter_voisin(liste.noeud[index], b);
		}else{
			printf("ajout noeud\n");
			nouveau = initialiser_noeud(a, b);
			afficher_noeud(nouveau);
			ajouter_noeud(&liste, nouveau);
		}
	}
	return liste;
}
