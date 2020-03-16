#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROT 1
#define SIZE 3000

int main()
 {
     int i=0, x, y;
     char *text;
     char *t;
     text = calloc(SIZE, sizeof(char));
     t = calloc(SIZE, sizeof(char));
     printf("skriv: ");
     fgets(text, 30, stdin);

     x=strlen(text)+1;

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
     strcpy(text, t);
     free(t);
     y = x-1;
     text[y] = '\0';
     printf("%s\n", text);
     free(text);
 }
