#include <stdlib.h>		//Plusieurs bibliothèques du langage C dont nous nous servons dans ce programme

#include <stdio.h>

#include <string.h>

#include <time.h>

#include <sys/types.h>

#include <unistd.h>



#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

#define TAILLE_MAX 1000		//Taille maximale de chaque  du fichier

#define LARGEUR_CONSOLE 80  // Largeur de la console


// On définit les valeurs attribuées au temps avec la fonction InitTime()

int InitTime()

{

	time_t secondes;

	struct tm instant;

	time(&secondes);

	instant=*localtime(&secondes);

// Attribution affichage du temps

	int TimeS1 = (instant.tm_sec)/10;

	int TimeS2 = (instant.tm_sec)-(TimeS1*10);

	int TimeM1 = (instant.tm_min)/10;

	int TimeM2 = (instant.tm_min)-(TimeM1*10);

	int TimeH1 = (instant.tm_hour)/10;

	int TimeH2 = (instant.tm_hour)-(TimeH1*10);

// Affichage HH:MM:SS  avec ("printf("%u%u : %u%u : %u%u\n",TimeH1 ,TimeH2,TimeM1 ,TimeM2,TimeS1 ,TimeS2);

	int Tab[8];

	Tab[0]=TimeH1;

	Tab[1]=TimeH2;

	Tab[2]=20;

	Tab[3]=TimeM1;

	Tab[4]=TimeM2;

	Tab[5]=20;

	Tab[6]=TimeS1;

	Tab[7]=TimeS2;



	int z = 0;

	int TailleFich = 1;



	int y=12, x=9;

	FILE* fichier1 = NULL;     		//Pointeur initialisé à NULL

	char chaine[TAILLE_MAX];        

	int chaine2[2];

        int i=0, j=0;				//Déclaration des deux variables pour les boucles

        int r,e;	



	fichier1 = (FILE*)malloc(sizeof(int));	//Permet d'allouer de la mémoire au pointeur fichier1


// On charge et on attribue les images PBM aux valeurs du tableau Tab créé précédemment


	for (z=0;z<8;z++)

	{

		switch (Tab[z])

		{

			case 0:

				fichier1 = fopen("chiffre0.pbm", "r");

				break;

			case 1:

				fichier1 = fopen("chiffre1.pbm", "r");

				break;
 
			case 2:

				fichier1 = fopen("chiffre2.pbm", "r");

				break;

			case 3:

				fichier1 = fopen("chiffre3.pbm", "r");

				break;

			case 4:

				fichier1 = fopen("chiffre4.pbm", "r");

				break;

			case 5:

				fichier1 = fopen("chiffre5.pbm", "r");

				break;

			case 6:

				fichier1 = fopen("chiffre6.pbm", "r");

				break;

			case 7:

				fichier1 = fopen("chiffre7.pbm", "r");

				break;

			case 8:

				fichier1 = fopen("chiffre8.pbm", "r");

				break;

			case 9:

				fichier1 = fopen("chiffre9.pbm", "r");

				break;

			case 20:

				fichier1 = fopen("2points.pbm", "r");

				break;

		}



//Affichage des images


		 if (fichier1 != NULL) 		//On peut lire le fichier

        	    {

        	        fseek(fichier1, 3, SEEK_SET);

        	        fscanf(fichier1, "%d %d", &chaine2[0], &chaine2[1]);

        	        r = chaine2[0];

        	        e = chaine2[1];

        	        r = (r*2)-1;



			fseek(fichier1, 1, SEEK_CUR);


//Boucle qui va parcourir les lignes

        	      	for(i=0; i<e; i++)

        	            {

				gotoxy(x,y);

				fgets(chaine, TAILLE_MAX, fichier1);	//récupération de la ligne


// On parcours chaque ligne et on remplace les '0' par ' ' et les '1' par '#'

        	                for(j=0; j<r; j++)

        	                    {

					gotoxy(x,y);

					if (chaine[j] == '0')

        	                            chaine[j] = ' ';

        	       			else if (chaine[j] == '1')

        	                            	chaine[j] = '#';

        	                    }

				x=x+1;

				printf("%s", chaine);	//Afficher l'image ligne par ligne

        	            }

				fclose(fichier1);   	//On ferme le fichier ouvert

				fichier1 = NULL;

				free(fichier1);		//Permet de libérer la mémoire allouer	

        	    }

		x=x-5;

		y=y+7;

	}



}



int main(int argc, char *argv[])

{



	int RefreshT = 10;	//Temps en seconde avant actualisation

	int ctrlc = 0;

	int k;

	int a=23, b=15, c=9, d=40;

	system("clear");	//Nettoiement de la console

	while (ctrlc != 1)

	{

		int y = 60;

		gotoxy(c,d);

		InitTime();

		gotoxy(a,b);

		printf("Cet écran sera actualisé dans quelques secondes");

		printf ("\n\n\n");

		

// Affichage des points chaque secondes après la phrase "Cet écran sera actualisé dans quelques secondes"

		for (k=0; k<RefreshT; k++)

		{

			sleep(1);

			gotoxy(a,y);

			printf(".\n");

			y++;

		}

		y=y-RefreshT;

		gotoxy(a,y);

		printf("                            ");

	}

	return 0;

}
