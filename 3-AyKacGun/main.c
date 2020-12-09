#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int ay;
    int gun;

    printf("gun sayisini ogrenmek istediginiz ayi giriniz : \n ");
    scanf("%d",&ay);

    if (ay >= 1 && ay <= 12)
    {
        switch (ay)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            gun = 30;
            break;
            case 2:
                gun = 28;
                break;
                default: gun = 31;

        }printf("girdiginiz ay %d gundur.",gun);
    }
    else printf("aralik disi deger girdiniz.");


    return 0;
}
