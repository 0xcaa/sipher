#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 30000

/* gör om gold bug så att den använder alphabetet på samma sätt som atbash
 * och sen gör if staser om det skulle vara speciella chars*/

int goldbug(void)
{

     int i=0, x, q, o=0;
     char *t;
     char *text;
     FILE *fp;
     char c;
     text = calloc(SIZE, sizeof(char));

     printf("Write a text string or a file path: ");
     fgets(text, SIZE, stdin);

      //radera \n från fgets
     for(q=0;q<strlen(text);q++)
     {
         if (text[q]=='\n')
             text[q]='\0';
     }

     x=strlen(text)+100;

     if((fp = fopen(text, "r+"))==0)
     {
         text = realloc(text, x * sizeof(char));
         t = (char*)calloc(x, sizeof(char));

         while((text[i]!='\0')&& (strlen(text))<x)
         {
             c = tolower(text[o]);
             switch(c)
             {
                 case 'a':
                    t[i] = '5';
                    break;
                 case 'b':
                    t[i] = '2';
                    break;
                 case 'c':
                    t[i] = '-';
                    break;
                 case 'd':
                    strcat(t, "\u2020");
                    i = strlen(t);
                    break;
                 case 'e':
                    t[i] = '8';
                    break;
                 case 'f':
                    t[i] = '1';
                    break;
                 case 'g':
                    t[i] = '3';
                    break;
                 case 'h':
                    t[i] = '4';
                    break;
                 case 'i':
                    t[i] = '6';
                    break;
                 case 'j':
                    t[i] = ',';
                    break;
                 case 'k':
                    t[i] = '7';
                    break;
                 case 'l':
                    t[i] = '0';
                    break;
                 case 'm':
                    t[i] = '9';
                    break;
                 case 'n':
                    t[i] = '*';
                    break;
                 case 'o':
                    t[i] = 'q';
                    break;
                 case 'p':
                    t[i] = '.';
                    break;
                 case 'q':
                    t[i] = '$';
                    break;
                 case 'r':
                    t[i] = '(';
                    break;
                 case 's':
                    t[i] = ')';
                    break;
                 case 't':
                    t[i] = ';';
                    break;
                 case 'u':
                    t[i] = '?';
                    break;
                 case 'v':
                    t[i] = 'q';
                    break;
                 case 'w':
                    t[i] = ']';
                    break;
                 case 'x':
                    t[i] = 'q';
                    break;
                 case 'y':
                    t[i] = ':';
                    break;
                 case 'z':
                    t[i] = '[';
                    break;


                 default:
                    i++;
                    continue;
             }

                 i++;
                 o++;
         }
         printf("%s\n", t);
         free(text);
         free(t);
         return 0;
     }

    else
    {
        printf("not done file cipher yet\n");
        return 0;
    }
}

