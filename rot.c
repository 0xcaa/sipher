#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define ROT 1
#define SIZE 30000

int rot_using_file(char *text,FILE **fp, int x);
int rot_nonfile(char *text, int x);

int rot(void)
{
     int x, q;
     char *text;
     FILE *fp;


     text = calloc(SIZE, sizeof(char));
     printf("Write a text string or a file path: ");
     fgets(text, SIZE, stdin);

      //radera \n från fgets
     for(q=0;q<strlen(text);q++) {
         if (text[q]=='\n')
             text[q]='\0';
     }

     x=strlen(text)+1;

     if((fp = fopen(text, "r+"))==0)
        rot_nonfile(text, x);

    else 
        rot_using_file(text, &fp, x);

    return 0;
}

int rot_nonfile(char *text, int x)
{
    char *t;
    int i=0;
    printf("%d\n", x);
    text = realloc(text, x * sizeof(char));
    t = (char*)calloc(x, sizeof(char));

         while((text[i]!='\0')&& (strlen(text))<x)
         {
             if(text[i]>122||text[i]<65)
             {
                 t[i]=text[i];
                 i++;
                 continue;
             }
             else if(text[i]>90 && text[i]<97) 
             {
                 t[i]=text[i];
                 i++;
                 continue;
             }
             if((text[i]+ROT)>122)
             {
                 t[i]=text[i]-25;
                 i++;
                 continue;
             }
             else if((text[i]+ROT)>90 && (text[i]+ROT)<97)
             {
                 t[i]=text[i]-25;
                 i++;
                 continue;
             }
             t[i]=text[i]+ROT;
             i++;
         }
         free(text);
         printf("%s\n", t);
         free(t);
         return 0;

}

int rot_using_file(char *text,FILE **fp, int x)
{
    char c, *t;
    int bytes, i=0;
    fseek(*fp, 0, SEEK_END);
    bytes = ftell(*fp);
    rewind(*fp);

    t = (char*)calloc(bytes+1, sizeof(char));

    while((c = getc(*fp)) != EOF)
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
    fclose(*fp);
    printf("%s", text);
    if((*fp = fopen(text, "w+"))==0)
        fprintf(stderr, "Premission denied\n");
    free(text);
    fputs(t, *fp);
    fclose(*fp);
    free(t);
    printf("done!\n");
    return 0;
}
