#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>

#define TAILLE_MAX 1000 // Tableau de taille 1000


int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    char  *filename;
    filename = argv[1];

    typedef struct size size;
    struct    size
    {
      int   row;
      int   col;
    };

    char* dimensions;
    char tab[TAILLE_MAX][TAILLE_MAX];
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
    int x =0;
    int j =0;
    int y =0;
    int i =0;
    int k =0;
    int a;
    int b;
    int retour;
    int espacement;
    fichier = fopen(filename, "r");

    if (fichier != NULL) 
    {   
      while(j<27)
        { y=0;
          x=0;
          fgets(chaine, TAILLE_MAX, fichier);
          if (j==1)
          { 
            printf("%s\n",chaine);
            dimensions=strtok(chaine," ");
            a=(dimensions[0]-48)*10+(dimensions[1]-48);
            b=(dimensions[3]-48)*10+(dimensions[4]-48);
            printf("%d\n",a );
            printf("%d\n",b );
          }
          
          while(j>1&&x<a)
          { 
            if (chaine[y]==48)
            { 
              tab[j][x]=chaine[y];
              
              x++;
            }

            else if (chaine[y]==49)
            {
              tab[j][x]=chaine[y];
              
              x++;
            }
              y++;
          }  
          j++;          
        }                     
      fclose(fichier);

    }
    struct  size  termsize;
    struct winsize  w;
    ioctl(0, TIOCGWINSZ, &w);
    termsize.row = w.ws_row;
    termsize.col = w.ws_col;
    printf("%d\n", termsize.col);
    printf("%d\n", termsize.row);
    
    
    retour=(termsize.row-b)/2;
    espacement=(termsize.col-a)/2;

    printf("%d\n", retour);
    printf("%d\n", espacement);

    for(i=0;i<=retour;i=i+1)
    {
      printf ("\n");
    }
    y=0;
    x=0;
    while (y<b)
    { for(i=0;i<=espacement;i=i+1)
      {
        printf (" ");
      }
      while (x<a)
      {       
                
        if (tab[y][x]=='1')
        {
          printf ("#");
        }
        if (tab[y][x]=='0')
        {
          printf (" ");
        }
        x++;
      }
      printf ("\n");
      y++;
      x=0;
    }
    for(i=0;i<=retour;i=i+1)
    {
      printf ("\n");
    }
    char c;
    while (42) {
      system("/bin/stty raw");
      c = getchar();
      if (c > 0 && c < 128) {
        system("/bin/stty cooked");
        exit(0);
      }
    }
}