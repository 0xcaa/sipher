#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define ROT 1
#define SIZE 3000

char *rot(char text[])
{
     int i=0, x, y;
     char *t;
     t = calloc(SIZE, sizeof(char));
     printf("write a text string or a file path: ");
     fgets(text, SIZE, stdin);

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
     return text;
 }
