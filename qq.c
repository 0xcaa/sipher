#include <stdio.h>
#include <string.h>

int main()
{
    char i[12]="\u2020";
    char q[30]="abcdefg";
    int x=3;
    strcat(q[x], i);
    printf("%s\n", q);
    return 0;
}
