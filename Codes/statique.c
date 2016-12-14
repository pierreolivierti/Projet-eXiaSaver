#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>

#include <string.h>

#include <time.h>

//#include <ncurses.h>

#define LARGEUR_CONSOLE 80





int main (int argc, char *argv[])



 {

//declaration des variables//

int i = 0;

int nombre_aleatoire = 0;

int m = 0;

FILE* fichier = NULL;

//declaration des variables du tableau//



int test = 0;

int dimension[2];

int width = 0;

int height = 0;

int size = 0;

char *tableau= NULL;

int j=0;



system("clear"); //appel  au term_clear

{

int rand_a_b(int a, int b) //intilalisation des valeurs randMIN & randMAX



{

    return rand()%(b-a) +a;

}





int nombre_aleatoire;



srand(time(NULL)); // initialisation de rand



	for(m=0; m<1; m++)

    {

        rand_a_b(1,7);

		nombre_aleatoire = rand_a_b(1,7); // choix d'un nombre aleatoire entre A & B

		printf("%d\n",nombre_aleatoire);

		fflush(stdout);

    }





if ( nombre_aleatoire == 1) // si le nombre aleatoire = 1  le pbm ouvert sera le 1.pbm



fichier = fopen (".pbm","r"); // si le nombre aleatoire = 1  le pbm ouvert sera le 1.pbm



else if (nombre_aleatoire == 2)

{

fichier = fopen (".pbm","r"); // si le nombre aleatoire = 2  le pbm ouvert sera le 2.pbm

}

else if (nombre_aleatoire == 3)

{

fichier = fopen (".pbm","r"); // si le nombre aleatoire = 3  le pbm ouvert sera le 3.pbm

}

else if (nombre_aleatoire == 4)

{

fichier = fopen ("/home/merouane/Desktop/Exia-saver/Term-saver1/4.pbm","r");// si le nombre aleatoire = 4  le pbm ouvert sera le 4.pbm

}

else if (nombre_aleatoire == 5)

{

fichier = fopen (".pbm","r");// si le nombre aleatoire = 5 le pbm ouvert sera le 5.pbm

}

else if (nombre_aleatoire == 6)

{

fichier = fopen (".pbm","r");// si le nombre aleatoire = 6  le pbm ouvert sera le 6.pbm

}



char caractere;



FILE *fs = NULL;

fs = fopen("ajouter au log.txt","a+"); // Ajouter le parametre du Term-saver1 au Log

fprintf(fs,"%d.pbm\n",nombre_aleatoire);

fclose(fs);



  if (fichier != NULL) // si l'image est bien recu

{

fseek (fichier, 14, SEEK_SET); //aller a la case 0x1 du fichier

fscanf(fichier, "%d %d", &dimension[0], &dimension[1]);//affichier le fihier

width = dimension[0];

height = dimension[1];

size = 2*width*height;

tableau = malloc(size * sizeof(char));//allouer un espace memoire pour le tableau contenant le fichier




do

  {

caractere = fgetc(fichier); //interpreter les 0 par des espaces

if (caractere == '0')

{caractere = ' '; tableau[i] = caractere, i++;}



else if (caractere == '1') //interpreter les 1 par des X

{caractere = 'X'; tableau[i] = caractere, i++;}



else if (caractere == '\n')//faire les retour a la ligne

{caractere = '\n'; tableau[i] = caractere, i++;}



}

while (caractere != EOF);//lire jusqu'a la fin du fichier





for(j;j<size; j++)

{

printf("%c",tableau[j]); //afficher les caracteres

fflush(stdout);

}

free(tableau);

}



//printf ("\n");

//char c;

//initscr();

//c = getchar();

//if (c != '\0');

//ndwin();

//system("clear");

return 0;

}









}
