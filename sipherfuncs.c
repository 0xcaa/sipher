#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define ROT 1
#define SIZE 30000


void atbash()
{
    int i=0, x, q, len;
    char *filename;
    char *text;

    FILE *fp;

    const char zlph_upper[27] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    const char zlph_lower[27] = "zyxwvutsrqponmlkjihgfedcba";
    const char alph_lower[27] = "abcdefghijklmnopqrstuvwxyz";
    const char alph_upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    text = (char*)calloc(SIZE, sizeof(char));

    printf("Write a text string or a file path: ");
    fgets(text, SIZE, stdin);
    len=strlen(text)+1;

      //radera \n från fgets
     for(q=0;q<strlen(text);q++)
     {
         if (text[q]=='\n')
         {
             text[q]='\0';
             break;
         }
     }

    filename = (char*)calloc(len, sizeof(char));
    strcpy(filename, text);

    if((fp = fopen(filename, "r+"))==0)
    {
        free(filename);
        text = realloc(text, len * sizeof(char));
        while(1)
        {
            for(x=0;x<=27;x++)
            {
                if(text[i]==alph_lower[x])
                {
                    text[i] = zlph_lower[x];
                    break;
                }
                else if(text[i]==alph_upper[x])
                {
                    text[i] = zlph_upper[x];
                    break;
                }
                else if(text[i]=='\0'||text[i]=='\n')
                    goto end;
            }
            i++;
        }
    }
    else
    {
        char c;
        int bytes;

        fseek(fp, 0, SEEK_END);
        bytes = ftell(fp);
        rewind(fp);

        text = realloc(text, (bytes+1) * sizeof(char));

        text[i] = '\0';
        while((c = getc(fp)))
        {
            for(x=0;x<=27;x++)
            {
                if(c==alph_lower[x])
                {
                    text[i] = zlph_lower[x];
                    break;
                }
                else if(c==alph_upper[x])
                {
                    text[i] = zlph_upper[x];
                    break;
                }
                else if(c==EOF)
                    goto fileend;
                else
                    text[i] = c;
            }
            i++;
        }
    }

    end:
    printf("%s\n", text);
    free(text);

    fileend:
    fclose(fp);
    fp = fopen(filename, "w+");
    fputs(text, fp);
    fclose(fp);
    free(text);
    free(filename);
    printf("Done!\n");
}




void gold(void)
{

     int i=0, x, q, bytes, o=0;
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
     }

    else
    {
        char c;
        fseek(fp, 0, SEEK_END);
        bytes = ftell(fp);
        rewind(fp);

        t = (char*)calloc(bytes+1, sizeof(char));
        free(text);

        while((c = getc(fp)) != EOF)
        {
             if(c>'z'||c<'A')
             {
                 t[i]=c;
                 i++;
                 continue;
             }
             else if(c>90 && c<97) 
             {
                 t[i]=c;
                 i++;
                 continue;
             }
             if((c+ROT)>122)
             {
                 t[i]=c-25;
                 i++;
                 continue;
             }
             else if((c+ROT)>90 && (c+ROT)<97)
             {
                 t[i]=c-25;
                 i++;
                 continue;
             }
             
             t[i]=c+ROT;
             i++;
        }
        fclose(fp);
        fp = fopen(text, "w+");
        fputs(t, fp);
        fclose(fp);
        free(t);
        printf("done!\n");
    }
}

