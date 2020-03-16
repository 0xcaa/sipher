#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sipherfuncs.h"
#include "usage.h"



int main(int argc, char **argv)
{
    char opt[5] = { 0 };
    char x[15] = "sipher";

    strncpy(opt, argv[3], 8);

    if(strcmp(opt, "-r"))
        rot(argv[3]);
    else
        printusage(x);
}
