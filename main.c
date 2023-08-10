#include <stdio.h>
#include "eleve.h"
#include <stdlib.h>
int main(){
	Eleve *lUne;
	int nombreEtudiant = 0;
	nombreEtudiant = nombreEleve();
	lUne = malloc(sizeof(Eleve) * (nombreEtudiant - 1));
	int taille = sizeof(lUne)/sizeof(lUne[0]);
	recupInfosEleve(lUne);
//	afficheEleve(lUne,nombreEtudiant - 1);
	printf("\n-------------------------------\n");
	printf("Apres triage\n");
	qsort(lUne,nombreEtudiant,sizeof(lUne[0]),compare);
	afficheEleve(lUne,nombreEtudiant);
	return 0;
	}
