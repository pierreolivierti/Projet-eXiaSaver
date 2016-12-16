#include "include/my.h"

int displayStats()
{
	int s=0;
	int i=0;
	int d=0;
	int c;
	int choice;
	int total;
	float pS;
	float pI;
	float pD;
	char ligne[255];
	
	system("clear");

	FILE* historique=fopen("/home/mrflyinrocket/Desktop/Projet-eXiaSaver/Codes/historique.txt","r");	//ouvre l'historique
	printf("1. Historique chronologique\n");
	printf("2. Historique par type\n");
	printf("3. Statistiques\n\n");
	printf("Entrez un chiffre : ");

	//scan du choice de l'ulitisateur
	while(choice<1 || choice>3)
	{
		scanf("%d",&choice);
	}
	switch(choice)
		{
		case 1:	//tri
			system("clear");
			printf("STATS:\n\n");
			while (fgets(ligne, 255, historique)!=NULL)	//affichage des logs
			{
				printf("%s", ligne);
			}
			fclose(historique);	// fermeture de l'historique
			exit(0);
			break;

		case 2:	//tri par type
			system("clear");
			printf("STATISTIQUES:\n\n");
			while (fgets(ligne, 255, historique)!=NULL)
			{
				if (ligne[20]=='1')
					printf("%s",ligne);
			}
			fclose(historique); //fermeture de l'historique				
			historique=fopen("historique.txt","r");	//ouverture de l'historique
			while (fgets(ligne, 255, historique)!=NULL)
			{
				if (ligne[20]=='2')
					printf("%s",ligne);
			}
			fclose(historique);
			historique=fopen("historique.txt","r");
			while (fgets(ligne, 255, historique)!=NULL)
			{
				if (ligne[20]=='3')
					printf("%s",ligne);
			}
			fclose(historique);
			exit(0);
			break;

		case 3:
			printf("STATISTIQUES\n\n");
			system("clear");
			while (fgets(ligne, 255, historique)!=NULL)
			{
				if (ligne[20]=='1')	//récupération du nombre d'ouverture de screensaver statiques
					s++;
			}
			fclose(historique); //fermeture de l'historique				
			historique=fopen("historique.txt","r");	//ouverture de l'historique
			while (fgets(ligne, 255, historique)!=NULL)
			{
				if (ligne[20]=='2')	//récupération du nombre d'ouverture de screensaver dynamique
					d++;
			}
			fclose(historique);
			historique=fopen("historique.txt","r");
			while (fgets(ligne, 255, historique)!=NULL)
			{
				if (ligne[20]=='3')	//récupération du nombre d'ouverture de screensaver interactif
					i++;
			}
			printf("%d  statiques\n%d  dynamiques\n%d  interactifs.\n\n",s,d,i);
			total=s+d+i;
			pS=((float)s/(total))*100;	//calcul des pourcentages
			pD=((float)d/(total))*100;
			pI=((float)i/(total))*100;
			printf("%f %% statiques\n%f %% dynamiques\n%f  %% interactifs.\n",pS,pD,pI);
			fclose(historique);
			exit(0);
			break;			
		}
	return 0;
}