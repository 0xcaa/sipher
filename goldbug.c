#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "atbash.h"

#define SIZE 30000

int gold_nonfile(char *text, int x);

const char gold_alph[50] = "52-\u202061346,709*\u2021.$();?q]¢:[";

int goldbug(void)
{
     int x, q;
     char *text;
     FILE *fp;
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

     if((fp = fopen(text, "r+"))==0){
         gold_nonfile(text, x);
         return 0;
     }

    else{
        printf("not done file cipher yet\n");
        return 0;
    }
    return 1;
}

int gold_nonfile(char *text, int x)
{
    int i;
    text = realloc(text, x * sizeof(char));

     while(1){
         text[i] = tolower(text[i]);
         for(x=0;x<=27;x++){
             if(text[i]==alph_lower[x]){
                 text[i]=gold_alph[x];
                 break;
             }
             else if(text[i]=='\0')
                 goto end;
        }
        i++;
    }

    end:
    printf("%s", text);
    for(i=0;text[i]!='\0';i++)
        printf("%c", text[i]);
    free(text);
    return 0;

}

