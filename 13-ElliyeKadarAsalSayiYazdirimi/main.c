#include <stdio.h>
#include <stdlib.h>

int main()
{

    char alfabe[26]={'a','b','c'};
    alfabe[10]='k';
    for(int i=0;i<26;i++)
        printf("%c\n",alfabe[i]);



    return 0;
}
