#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "usage.h"
#include "sipherfuncs.h"
#include "rot.h"

int main(int argc, char **argv)
{
    int opt;
    if (argc!=2)
    {
        printusage(argv[0]);
        exit(255);
    }

    while((opt = getopt(argc, argv, "rulag")) != -1)
        switch(opt)
        {
            case 'r':
                rot();
                break;
            case 'a':
                atbash();
                break;
             case 'g':
                gold();
                break;
            case 'u':
                printusage(argv[0]);
                break;
            case 'l':
                list();
                break;

        default:
            perror("Invalid Option");
            return 1;
        }

    return 0;
}
