#include "include/my.h"

FILE* getFichier(int valeur){
	switch(valeur){
		case 0:
			return fopen("Chiffres/chiffre0.pbm","r");
			break;

		case 1:
			return fopen("Chiffres/chiffre1.pbm","r");
			break;

		case 2:
			return fopen("Chiffres/chiffre2.pbm","r");
			break;

		case 3:
			return fopen("Chiffres/chiffre3.pbm","r");
			break;

		case 4:
			return fopen("Chiffres/chiffre4.pbm","r");
			break;

		case 5:
			return fopen("Chiffres/chiffre5.pbm","r");
			break;

		case 6:
			return fopen("Chiffres/chiffre6.pbm","r");
			break;

		case 7:
			return fopen("Chiffres/chiffre7.pbm","r");
			break;

		case 8:
			return fopen("Chiffres/chiffre8.pbm","r");
			break;

		case 9:
			return fopen("Chiffres/chiffre9.pbm","r");
			break;
	}
}

void displayTime(FILE* fichier0, FILE* fichier1, FILE* fichier2, FILE* fichier3, FILE* fichier4, FILE* fichier5, FILE* fichierX, int sizeX, int sizeY, int size) {// Affichage de l'image!

	int i = 0;
	int j = 0;
	int k = 0;
	int n=35;
	char line0[10], line1[10] ,line2[10], line3[10], line4[10], line5[10], points[10];
	system("clear");
	for (i=0; i<sizeY; i++) {
		printf("\n");
	} //nombre de retour a la line pour le positionnement de l'image en Y
	for (i=0; i<8; i++) {//pour chaques lines du fichier
		for (j=0; j<sizeX; j++) { 
			printf(" ");
		} //nombre d'espaces pour le positionnement de l'image en X
		fgets(points, 10, fichierX);
		fgets(line0, 10, fichier0);
		fgets(line1, 10, fichier1);
		fgets(line2, 10, fichier2);
		fgets(line3, 10, fichier3);
		fgets(line4, 10, fichier4);
		fgets(line5, 10, fichier5);
		if (i>=3){
			for (k=0; k<6; k++) { // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (line0[k]=='1') {
					printf("%c",n);
				}
				if (line0[k]=='0') {
					printf(" ");
				}
				if (k==5) {
					printf(" ");
				}
				if (size==2) {
					printf(" ");
				}
			}
			for (k=0; k<6; k++) { // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (line1[k]=='1') {
					printf("%c",n);
				}
				if (line1[k]=='0') {
					printf(" ");
				}
				if (k==5) {
					printf(" ");
				}
				if (size==2) {
					printf(" ");
				}
			}
			for (k=0; k<6; k++) { // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (points[k]=='1') {
					printf("%c",n);
				}
				if (points[k]=='0') {
					printf(" ");
				}
				if (k==5) {
					printf(" ");
				}
				if (size==2) {
					printf(" ");
				}
			}
			for (k=0; k<6; k++) { // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (line2[k]=='1') {
					printf("%c",n);
				}
				if (line2[k]=='0') {
					printf(" ");
				}
				if (k==5) {
					printf(" ");
				}
				if (size==2) {
					printf(" ");
				}
			}
			for (k=0; k<6; k++) { // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (line3[k]=='1') {
					printf("%c",n);
				}
				if (line3[k]=='0') {
					printf(" ");
				}
				if (k==5) {
					printf(" ");
				}
				if (size==2) {
					printf(" ");
				}
			}
			for (k=0; k<6; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (points[k]=='1') {
					printf("%c",n);
				}
				if (points[k]=='0') {
					printf(" ");
				}
				if (k==5) {
					printf(" ");
				}
				if (size==2) {
					printf(" ");
				}
			}
			for (k=0; k<6; k++) { // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (line4[k]=='1') {
					printf("%c",n);
				}
				if (line4[k]=='0') {
					printf(" ");
				}
				if (k==5) {
					printf(" ");
				}
				if (size==2) {
					printf(" ");
				}
			}
			for (k=0; k<6; k++) { // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (line5[k]=='1') {
					printf("%c",n);
				}
				if (line5[k]=='0') {
					printf(" ");
				}
				if (k==5) {
					printf(" ");
				}
				if (size==2) {
					printf(" ");
				}
			}	
		}
		printf("\n");
	}
}

int rand_a_b(int a, int b){
	srand(time(NULL)); // fonction random aux bornes [a;b[
    	return rand()%(b-a) +a;
}