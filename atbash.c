#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define ROT 1
#define SIZE 30000

const char zlph_upper[27] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
const char zlph_lower[27] = "zyxwvutsrqponmlkjihgfedcba";
const char alph_lower[27] = "abcdefghijklmnopqrstuvwxyz";
const char alph_upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int atbash_nonfile(char *text, int x);
int atbash_using_file(char *text, FILE **fp, int len);

int atbash()
{
    int q, len;
    char *text;
    FILE *fp;

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

    if((fp = fopen(text, "r+"))==0)
    {
        atbash_nonfile(text, len);
        free(text);
        return 0;
    }
    else
    {
        atbash_using_file(text, &fp, len);
        free(text);
        return 0;
    }
}

int atbash_nonfile(char *text, int len)
{
    int i, x;
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
    end:
    printf("%s\n", text);
    return 0;
}


int atbash_using_file(char *text, FILE **fp, int len)
{
    char c;
    char filename[len];
    int bytes, x, i=0;

    strncpy(filename, text, len+1);

    fseek(*fp, 0, SEEK_END);
    bytes = ftell(*fp);
    rewind(*fp);

    text = realloc(text, (bytes+1) * sizeof(char));

    text[i] = '\0';
    while((c = getc(*fp)))
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
    fileend:
    fclose(*fp);
    *fp = fopen(filename, "w+");
    fputs(text, *fp);
    fclose(*fp);
    printf("Done!\n");
    return 0;
}
