#include "tableaux.h"

void vider_tableau(int hauteur, int largeur, float** tableau){
	for (int i = 0; i < hauteur; i++)
	{
		free(tableau[i]);
	}
	free(tableau);
}

void afficher_tableau(int hauteur, int largeur, float** tableau){
	for (int i = 0; i < hauteur; i++)
	{
		printf("(");
		for (int j = 0; j < largeur; j++)
		{
			printf(" %.4f", tableau[i][j]);
		}
		printf(" )\n");
	}
}

void saisir_tableau(int hauteur, int largeur, float** tableau){
	int a;
	for (int i = 0; i < hauteur; i++)
	{
		for (int j = 0; j < largeur; j++)
		{
			printf("Saisir le %de reel de la %de ligne\n",i,j );
			a = scanf("%f", &tableau[i][j]);
		}
	}
}

float** creer_tableau(int hauteur, int largeur){
	float** tableau;
	tableau = (float**)malloc(hauteur*sizeof(float*));
	for (int i = 0; i < hauteur; i++){
		tableau[i] = (float*)malloc(largeur*sizeof(float));
	}

	return tableau;
}

void creer_tableau_void(int hauteur, int largeur, float*** tableau){
	printf("debut allocation\n");
	*tableau = (float**)malloc(hauteur*sizeof(float*));
	printf("hauteur allouee\n");
	for (int i = 0; i < hauteur; i++){
		printf("debut allocation %d\n", i);
		(*tableau)[i] = (float*)malloc(largeur*sizeof(float));
		printf("largeur allouee %d fois\n",i );
	}
	printf("allocation terminee\n");
}
