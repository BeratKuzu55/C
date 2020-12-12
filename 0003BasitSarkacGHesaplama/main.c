#include <stdio.h>
#include <math.h>

float find_gravity_value(float l,float t);


int main() {
    float lenght[100],period_serial[100],g_seri[100];
    int i=0;
    printf("basit sarkac deneyi g degeri hesaplama uygulamasina hos geldiniz : ");
    printf("\nfloat sayi girerken nokta kullaniniz!!!");
    int control=1;
    float rope_lenght,period;
    do
    {
        printf("\nip uzunlugu giriniz : ");
        scanf("%f",&rope_lenght);
        printf("\nperiyot bilgisi giriniz :");
        scanf("%f",&period);

       float g = find_gravity_value(rope_lenght,period);
       printf("bulunan g degeri : %f ",g);

        lenght[i]=rope_lenght;
            period_serial[i]=period;
            g_seri[i]=g;
            i++;
       printf("\n\n\nyeni deger hesaplamak istemiyorsaniz 0 i tuslayiniz yeni hesap icin 1 i tuslayiniz.");

       scanf("%d",&control);



    } while (control==1);

    for(int j=0;j<i;j++)
    {
        printf("\n uzunluk : %f  periyot : %f  g : %f",lenght[j],period_serial[j],g_seri[j]);
    }
    printf("iyi gunler dileriz");




    return 0;
}


float find_gravity_value(float l,float t)
{

    return (4*pow(3.14,2)*l)/pow(t,2);

}





