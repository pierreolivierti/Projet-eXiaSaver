#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))


struct tm instant;

int decouperheures(struct tm instant);

int TimeH2 = 0;

int TimeH1 = 0;

int TimeM1 = 0;

int TimeM2 = 0;

int TimeS1 = 0;

int TimeS2 = 0;

int valeuractuelle = 0;



int decouperheures(struct tm instant)
{
        int TimeS1 = (instant.tm_sec)/10;

        int TimeS2 = (instant.tm_sec)-(TimeS1*10);

        int TimeM1 = (instant.tm_min)/10;

        int TimeM2 = (instant.tm_min)-(TimeM1*10);

        int TimeH1 = (instant.tm_hour)/10;

        int TimeH2 = (instant.tm_hour)-(TimeH1*10);

        if (TimeH1 == 1)

        printf("%u%u : %u%u : %u%u\n",TimeH1 ,TimeH2,TimeM1 ,TimeM2,TimeS1 ,TimeS2);

}




int main(int argc, char *argv[])

{

        time_t secondes;

        time(&secondes);

        instant=*localtime(&secondes);

	decouperheures(instant);

	char tableau[4][30] = {0};

        int RefreshT = 10;

        int ctrlc = 0;

        int i,j,l;

        int a = 23, b = 25, c = 11.5, d = 45;

	char caractere;

	int k = 0;

	int z, v = 0;

        system("clear");

        while (ctrlc != 1)

        {

                int y = 72;

                gotoxy(c,d);

                gotoxy(a,b);

                printf("Cet écran sera actualisé dans quelques secondes");

                printf ("\n\n\n");

                for (i=0; i<RefreshT; i++)

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


	for (i ; i < 8; i++)
	{
		if (i == 0)
		{ valeuractuelle = TimeH1;}

		else if (i == 1)
		{ valeuractuelle = TimeH2;}

		else if (i == 2)
    		{ valeuractuelle = 29;}

   		else if ( i == 3)
    		{ valeuractuelle = TimeM1;}

    		else if ( i == 4)
    		{ valeuractuelle = TimeM2;}

    		else if (i == 5)
    		{ valeuractuelle = 29;}

	FILE* fichier = NULL;


  	switch(valeuractuelle)
  	{
		case 0 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/chiffre0.pbm", "r" ); //OUVRE LE FICHIER
		break;

		case 1 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/chiffre1.pbm", "r" );
		break;

		case 2 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/chiffre2.pbm", "r" );
		break;

		case 3 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/chiffre3.pbm", "r" );
		break;

		case 4 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/chiffre4.pbm", "r" );
		break;

		case 5 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/chiffre5.pbm", "r" );
		break;

		case 6 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/chiffre6.pbm", "r" );
		break;

		case 7 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/chiffre7.pbm", "r" );
		break;

		case 8 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/chiffre8.pbm", "r" );
		break;

		case 9 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/chiffre9.pbm", "r" );
		break;

		case 29 :
		fichier = fopen("/home/Vincent/Projet2/Programmes/DossierProjet/2points.pbm", "r" );
		break;


		default :
		printf(" ");
		break;
	}

	if (fichier != NULL)
	{
		system("clear");
		fseek(fichier, 18, SEEK_SET);

		do
		{

    			for (k = 0; k < 30; k++)
			{
    				v = 0;


    			for (l = 0; l < 3; l++)
			{
				caractere = fgetc(fichier);

    			if ( caractere == '0')
    			{
				caractere = ' ';

     				tableau[c][v] = caractere;

      				v++;
    			}

   			else if ( caractere == ' ')
    			{
      				caractere = ' ';

     				tableau[c][v] = caractere;

      				v++;
    			}

    			else if ( caractere == '1')
    			{

      				caractere = 'X';

      				tableau[c][v] = caractere;

    				v++;
    			}

    			printf("%c", caractere);

		       }
		z++;
		}

		}while (caractere != EOF);

	       }
	else
	{

		printf("Le fichier ne peut pas être ouvert\n");
	}

	}

return 0;

}
