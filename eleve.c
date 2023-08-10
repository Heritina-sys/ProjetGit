#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eleve.h"
int nombreEleve(){
	FILE *fic = fopen("Students.csv","r");
	int nbLigne = 0;	//variable utilise pour compter et recuperer le nombre de ligne
	char c;			//varaible utililse pour savoir si c'est la fin du fichier ou non	
	if(fic == NULL){
			printf("Erreur lors de l'ouverture du ficher\n");
			return 1;
	}
	while((c = fgetc(fic)) != EOF){
		if(c == '\n')		//on teste si c'est une fin a la ligne et si c'est le cas ,on incriment nbLigne'
			nbLigne++;
	}
	fclose(fic);
	return nbLigne;	
}
void recupInfosEleve(Eleve *perso){
	char *nonUtilise = NULL;	//variable utilise pour ignorer le premier ligne 
	size_t taille = 0;
	FILE *fic = fopen("Students.csv","r");
	int nombreEtudiant = 0;
	nombreEtudiant = nombreEleve();
	getline(&nonUtilise,&taille,fic);
	for(int i = 0;i < nombreEtudiant;i++){
		getline(&nonUtilise,&taille,fic);
		char *token = strtok(nonUtilise,",");
	//	printf("%s\n",nonUtilise);
		if(token){
			strcpy(perso[i].nom,token);
			token = strtok(NULL,",");
		}	
		if(token){
			strcpy(perso[i].prenom,token);
			token = strtok(NULL,",");
		}
		if(token){
			strcpy(perso[i].dateNaissance,token);
			token = strtok(NULL,",");
		}
		if(token){
			strcpy(perso[i].adresse,token);
			token = strtok(NULL,",");
		}
		if(token){
			strcpy(perso[i].telephone,token);
			token = strtok(NULL,",");
		}
		if(token){
			strcpy(perso[i].genre,token);
			token = strtok(NULL,",");
		}
		if(token){
			strcpy(perso[i].parcours,token);
			token = strtok(NULL,",");
		}
	}
	fclose(fic);
}
void afficheEleve(Eleve *perso,int taille){
	for(int i = 0;i < taille ;i++){
		printf("%s %s %s %s %s %s %s\n",perso[i].nom, perso[i].prenom ,perso[i].dateNaissance,perso[i].adresse,perso[i].telephone,perso[i].genre,perso[i].parcours);
		printf("\n\n");
	//	printf("%s\n",perso[i].prenom);
	}
}
/// Fonction qui permute deux eleve

int compare(const void *a,const void *b){
	Eleve *eleveA = (Eleve *)a;
	Eleve *eleveB =(Eleve *)b;
	int comparaisonNoms = strcmp(eleveA->nom,eleveB->nom);
		return comparaisonNoms;
/*
	  meme principe que :
			t = a
			a = b
			b = t

		char tmp_nom[100];

		char tmp_prenom[100];
		char tmp_dateNaissance[100];
		char tmp_telephone[100];
		char tmp_adresse[100];
		char tmp_genre[100];
		char tmp_parcours[100];
		
		strcpy(tmp_nom,el1.nom);
		strcpy(el1.nom,el2.nom);
		strcpy(el2.nom,tmp_nom);
		
		strcpy(tmp_prenom,el1.prenom);
		strcpy(el1.prenom,el2.prenom);
		strcpy(el2.prenom,tmp_prenom);
		
		strcpy(tmp_dateNaissance,el1.dateNaissance);
		strcpy(el1.dateNaissance,el2.dateNaissance);
		strcpy(el2.dateNaissance,tmp_dateNaissance);
		
		strcpy(tmp_telephone,el1.telephone);
		strcpy(el1.telephone,el2.telephone);
		strcpy(el2.telephone,tmp_telephone);
		
		strcpy(tmp_adresse,el1.adresse);
		strcpy(el1.adresse,el2.adresse);
		strcpy(el2.adresse,tmp_adresse);
		
		strcpy(tmp_genre,el1.genre);
		strcpy(el1.genre,el2.genre);
		strcpy(el2.genre,tmp_genre);
		
		strcpy(tmp_parcours,el1.parcours);	
		strcpy(el1.parcours,el2.parcours);
		strcpy(el2.parcours,tmp_parcours);
*/	
}
/*
void triEleve(Eleve *el1,int taille){
	int resultat = 0;
	for(int i = 0;i < taille;i++){
			for(int j = i;j < taille - 1;j++){
				resultat = strcmp(el1[j].nom,el1[j+1].nom);
				if(resultat < 0){
			//		printf("%d vrai\n",j);
					compare(el1[j],el1[j+1]);	
				}	
			}		
	}
}
*/
