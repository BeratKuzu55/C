#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  //  sleep()  icin


int main()
{



    //sleep(5);
    random_dizi();
    buyukten_kucuge_dizi();
    kucukten_buyuge_dizi();

    return 0;
}


void random_dizi()
{
     printf("dizinin eleman sayisini giriniz \n");
     int eleman_sayisi= 0;
     scanf("%d",&eleman_sayisi);

     int dizi[eleman_sayisi];

    srand(time(NULL));
    int r = 0;
    for(int i = 0; i<eleman_sayisi; i++)
    {
        r = rand();
       // printf("%d\n",r );

        dizi[i] = r;

    }


            time_t begin = time(NULL);

    selectionSort(dizi,eleman_sayisi);

            time_t end = time(NULL);
    printf("random dizi icin gecen sure %d saniye\n", (end - begin));
}




void buyukten_kucuge_dizi()
{
    printf("dizinin eleman sayisini giriniz \n");
    int eleman_sayisi= 0;
    scanf("%d",&eleman_sayisi);


    int dizi[eleman_sayisi];

    int deger = 500000;

    for(int i = 0; i<eleman_sayisi; i++)
    {
       dizi[i] = deger-i;
       //printf("%d\n",dizi[i]);
    }



        time_t baslangic = time(NULL);
    selectionSort(dizi,eleman_sayisi);
        time_t bitis = time(NULL);

        printf("buyukten kucuge siralanmis dizi icin gecen sure %d saniye\n",(bitis-baslangic));
}





void kucukten_buyuge_dizi()
{
     printf("dizinin eleman sayisini giriniz \n");
    int eleman_sayisi= 0;
    scanf("%d",&eleman_sayisi);

    int dizi[eleman_sayisi];

    int deger = 0;

    for(int i = 0; i<eleman_sayisi; i++)
    {
       dizi[i] = deger+i;
       //printf("%d\n",dizi[i]);
    }

        time_t baslangic = time(NULL);
    selectionSort(dizi,eleman_sayisi);
        time_t bitis = time(NULL);
        printf("kucukten buyuge siralanmis dizi icin gecen sure %d saniyedir\n",(bitis-baslangic));
}




void selectionSort (int list[], int last)
    {
    // Local Declarations
    int smallest;
    int holdData;

    // Statements
    for (int current = 0; current < last; current++)
     {
     smallest = current;
     for (int walker = current + 1; walker <= last; walker++)
        if (list[ walker ] < list[ smallest ])
            smallest = walker;

     // Smallest selected: exchange with current
     holdData = list[ current ];
     list[current] = list[ smallest ];
     list[smallest] = holdData;
     } // for current
    return;
} // selectionSort










