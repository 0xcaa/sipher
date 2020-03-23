#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 3000

int main()
 {
     int i, x;
     char *text;
     const char zlph_upper[27] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
     const char zlph_lower[27] = "zyxwvutsrqponmlkjihgfedcba";
     const char alph_lower[27] = "abcdefghijklmnopqrstuvwxyz";
     const char alph_upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

     text = calloc(SIZE, sizeof(char));
     printf("skriv: ");
     fgets(text, 30, stdin);


    for(i=0;i<=27;i++)
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
        }
    }

     printf("%s\n", text);
     free(text);
 }
