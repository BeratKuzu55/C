#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a,b,c,d,e;
    printf("5 adet sayi giriniz :");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    float ortalama=(a+b+c+d+e)/5;
    printf("%f",ortalama);

    return 0;
}
