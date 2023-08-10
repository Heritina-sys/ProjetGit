#ifndef __BL__
#define __BL__
typedef struct{
	char nom[100];
	char prenom[100];
	char dateNaissance[100];
	char adresse[100];
	char telephone[100];
	char genre[100];
	char parcours[100]; 	
}Eleve;
int nombreEleve();
void recupInfosEleve(Eleve *perso);
void afficheEleve(Eleve *perso,int taille);
int compare(const void *a,const void *b);
//void triEleve(Eleve *el1,int taille);
#endif
