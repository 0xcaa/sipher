#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define ROT 1
#define SIZE 30000

char *rot(char text[])
{
     int i=0, x, q, bytes;
     char *t;
     FILE *fp;

     printf("Write a text string or a file path: ");
     fgets(text, SIZE, stdin);

      //radera \n från fgets
     for(q=0;q<strlen(text);q++)
     {
         if (text[q]=='\n')
             text[q]='\0';
     }

     x=strlen(text)+1;
     t = calloc(SIZE, sizeof(char));

     if((fp = fopen(text, "r+"))==0)
     {
         t = realloc(t, (x) * sizeof(char));
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

    else
    {
        char c;
        fseek(fp, 0, SEEK_END);
        bytes = ftell(fp);
        rewind(fp);

        t = realloc(t, (bytes+1) * sizeof(char));
        text =  realloc(text, (bytes+1) * sizeof(char));

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
        strcpy(text, t);
        free(t);
        return "done!";
    }
 }




char* atbash(char text[])
{
    int i=0, x, q, len;
    FILE *fp;
    char *filename;

    const char zlph_upper[27] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    const char zlph_lower[27] = "zyxwvutsrqponmlkjihgfedcba";
    const char alph_lower[27] = "abcdefghijklmnopqrstuvwxyz";
    const char alph_upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


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

    filename = calloc(50, sizeof(char));
    strncpy(filename, text, 50);

    if((fp = fopen(filename, "r+"))==0)
    {
        text = realloc(text, len);
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

        text =  realloc(text, (bytes+1) * sizeof(char));
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
    return text;

    fileend:
    fclose(fp);
    fp = fopen(filename, "w+");
    fputs(text, fp);
    free(filename);
    fclose(fp);
    return "done!";
}
