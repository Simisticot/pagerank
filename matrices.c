#include "matrices.h"

t_matrice creer_matrice(int hauteur, int largeur){
	t_matrice matrice;
	matrice.hauteur = hauteur;
	matrice.largeur = largeur;
	matrice.tableau = creer_tableau(hauteur,largeur);

	return matrice;
}

t_matrice matrice_zero(int hauteur, int largeur){
	t_matrice matrice_zero;
	matrice_zero = creer_matrice(hauteur,largeur);
	for (int i = 0; i < hauteur; i++)
	{
		for (int j = 0; j < largeur; j++)
		{
			 matrice_zero.tableau[i][j] = 0;
		}
	}
	return matrice_zero;
}

t_matrice remplir_matrice(t_matrice matrice){
	saisir_tableau(matrice.hauteur,matrice.largeur,matrice.tableau);
	return matrice;
}

void afficher_matrice(t_matrice matrice){
	printf("Largeur : %d\n",matrice.largeur);
	printf("hauteur : %d\n",matrice.hauteur);
	afficher_tableau(matrice.hauteur, matrice.largeur, matrice.tableau);
}

t_matrice produit_matriciel(t_matrice matrice1, t_matrice matrice2){
	int i,j,k,l;
	t_matrice resultat;
	float case_courante;

	resultat = creer_matrice(matrice1.hauteur, matrice2.largeur);

	printf("début de boucle\n");
	for (i = 0; i < resultat.hauteur; i++)
	{
		printf("boucle hauteur\n");
		for (j = 0; j < resultat.largeur; j++)
		{
			printf("boucle largeur\n");
			case_courante = 0;
			for (k = 0; k < matrice1.largeur; k++)
			{
				case_courante += matrice1.tableau[i][k]*matrice2.tableau[k][j];
				printf("i = %d\n",i );
				printf("j = %d\n",j );
				printf("k = %d\n",k );
				printf("%.2f * %.2f = %.2f\n",matrice1.tableau[i][k],matrice2.tableau[k][j],matrice1.tableau[i][k]*matrice2.tableau[k][j] );
			}
			
			printf("case courante = %.2f\n",case_courante );
			resultat.tableau[i][j] = case_courante;
			afficher_matrice(matrice2);
		}
	}

	return resultat;
}

void vider_matrice(t_matrice matrice){
	vider_tableau(matrice.hauteur, matrice.largeur, matrice.tableau);
}