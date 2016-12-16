#include <stdlib.h>		//Plusieurs bibliothèques du langage C dont nous nous servons dans ce programme
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

#include "include/my.h"

// On définit les valeurs attribuées au time avec la fonction InitTime()

int initTime()
{
	time_t timet;
	typedef struct tm tm;
	tm instant;
	struct winsize w;
	int sizeX;
	int sizeY;
	int size;
	int i;
	int n;
	int longueur = 31;
	int largeur = 8;
	int ctrlc = 0;

// Attribution affichage du timet

	size=rand_a_b(1,3); //nb alea
	if (size==2) {
		longueur=62;
	}

	while (ctrlc != 1) { 
		time(&timet); //on recupere le timet
		instant=*localtime(&timet);
		ioctl(1, TIOCGWINSZ, &w); //fonction mettant dans les variable ws_row et ws_col la size de la fenetre
		sizeY=(w.ws_row-largeur)/2; //calcul de la position de l'image
		sizeX=(w.ws_col-longueur)/2;

		int TimeS1 = (instant.tm_sec)/10;
		int TimeS2 = (instant.tm_sec)-(TimeS1*10);
		int TimeM1 = (instant.tm_min)/10;
		int TimeM2 = (instant.tm_min)-(TimeM1*10);
		int TimeH1 = (instant.tm_hour)/10;
		int TimeH2 = (instant.tm_hour)-(TimeH1*10);


		FILE* fichier0=getFichier(TimeH1);
		FILE* fichier1=getFichier(TimeH2);
		FILE* fichier2=getFichier(TimeM1); //choix des bons fichiers en fonction des fichieréros
		FILE* fichier3=getFichier(TimeM2);
		FILE* fichier4=getFichier(TimeS1);
		FILE* fichier5=getFichier(TimeS2);
		FILE* fichierX=fopen("Chiffres/2points.pbm", "r");


		displayTime(fichier0, fichier1, fichier2, fichier3, fichier4, fichier5, fichierX, sizeX, sizeY, size); //affichage de l'jeure
	// Affichage HH:MM:SS  avec ("printf("%u%u : %u%u : %u%u\n",TimeH1 ,TimeH2,TimeM1 ,TimeM2,TimeS1 ,TimeS2);
	
		//printf("\n\n");
		for (n=0; n<sizeX; n++){
				printf(" ");
			}
		char *msg = "ACTUALISATION DANS 10 SECONDES!";
		printf("%s\n", msg); 
		
		for (i=0; i<10; i++){
			for (n=0; n<sizeX+longueur/2; n++){
				printf(" ");
			}
			sleep(1); //mise en pause de la console pour une seconde
			//printf(".");
			//strcat(msg, ".");
		}
		fclose(fichier0);
		fclose(fichier1);
		fclose(fichier2);
		fclose(fichier3); //fermeture du fichier
		fclose(fichier4);
		fclose(fichier5);
		fclose(fichierX);
	}
}
		
int main(int argc, char *argv[])
{
	initTime();
}