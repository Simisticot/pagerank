#include "matrices.h"

t_matrice creer_matrice(int hauteur, int largeur){
	t_matrice matrice;
	matrice.hauteur = hauteur;
	matrice.largeur = largeur;
	matrice.tableau = creer_tableau(hauteur,largeur);

	return matrice;
}

t_matrice matrice_uniforme(int hauteur, int largeur, float valeur){
	t_matrice matrice;
	matrice = creer_matrice(hauteur,largeur);
	for (int i = 0; i < hauteur; i++)
	{
		for (int j = 0; j < largeur; j++)
		{
			 matrice.tableau[i][j] = valeur;
		}
	}
	return matrice;
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

	for (i = 0; i < resultat.hauteur; i++)
	{
		for (j = 0; j < resultat.largeur; j++)
		{
			case_courante = 0;
			for (k = 0; k < matrice1.largeur; k++)
			{
				case_courante += matrice1.tableau[i][k]*matrice2.tableau[k][j];
			}
			
			resultat.tableau[i][j] = case_courante;
		}
	}

	return resultat;
}

void vider_matrice(t_matrice matrice){
	vider_tableau(matrice.hauteur, matrice.largeur, matrice.tableau);
}

t_matrice lire_matrice(){
	int hauteur;
	int largeur;
    char name[] = "adjacence";
    FILE *fichier;
    fichier = fopen(name, "r");
    if(fichier == NULL){
        perror("Erreur à l'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }

	fscanf(fichier,"%d,%d\n",&hauteur, &largeur);
	t_matrice matrice = creer_matrice(hauteur, largeur);

	for(int i = 0; i < hauteur; i++){
		for(int j = 0; j < largeur; j++){
			fscanf(fichier,"%f,",&matrice.tableau[i][j]);
		}
	}

    fclose(fichier);
	return matrice;
}

double norme_vecteur(t_matrice vecteur){
	int n,i;
	double norme;
	char largeur = 0;
	if(vecteur.hauteur == 1){
		n = vecteur.largeur;
		largeur = 1;
	}else if(vecteur.largeur == 1){
		n = vecteur.hauteur;
	}else{
		perror("Cette matrice n'est pas un vecteur\n");
		afficher_matrice(vecteur);
		exit(EXIT_FAILURE);
	}
	if(largeur){
		for (i = 0; i < n; i++){
			norme += pow((double)vecteur.tableau[0][i],2);
		}
	}else{
		for (i = 0; i < n; i++){
			norme += pow((double)vecteur.tableau[i][0],2);
		}
	}
	return sqrt(norme);
}

t_matrice somme_matricielle(t_matrice a, t_matrice b){
	if(!(a.hauteur == b.hauteur && a.largeur == b.largeur)){
		perror("Ces matrices ne sont pas de mêmes dimensions");
		exit(EXIT_FAILURE);
	}
	int i,j;
	t_matrice somme = creer_matrice(a.hauteur, a.largeur);
	
	for (i = 0; i < a.hauteur; i++){
		for (j = 0; j < a.largeur; j++){
			somme.tableau[i][j] = a.tableau[i][j] + b.tableau[i][j];
		}
	}
	return somme;
}

t_matrice difference_matricielle(t_matrice a, t_matrice b){
	if(!(a.hauteur == b.hauteur && a.largeur == b.largeur)){
		perror("Ces matrices ne sont pas de mêmes dimensions");
		exit(EXIT_FAILURE);
	}
	int i,j;
	t_matrice somme = creer_matrice(a.hauteur, a.largeur);
	
	for (i = 0; i < a.hauteur; i++){
		for (j = 0; j < a.largeur; j++){
			somme.tableau[i][j] = a.tableau[i][j] - b.tableau[i][j];
		}
	}
	return somme;
}

double norme_diff_vecteur(t_matrice a, t_matrice b){
	t_matrice diff = difference_matricielle(a,b);
	double norme = norme_vecteur(diff);
	vider_matrice(diff);
	return norme;
}

t_matrice copie_matrice(t_matrice a){
	int i,j;
	t_matrice b = creer_matrice(a.hauteur,a.largeur);
	for (i = 0; i < a.hauteur; i++){
		for (j = 0; j < a.largeur; j++){
			b.tableau[i][j] = a.tableau[i][j];
		}
	}
	return b;
}