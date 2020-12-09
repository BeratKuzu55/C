#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

   int sayi,sayi2;
   srand(time(0));     /* srand (sistem saatine gore rastgele sayi uretir)time(0) ý
                        kullanarak yoksa bunu kullanmazsak hep ayni sayiyi uretir.*/
   sayi = rand()%100; //rand rastgele bir sayi uretir 0 ile int in son degeri arasinda
                        //bu yuzden 100 e gore modunu aldik

    for (;;)
        {
            printf("sayi giriniz : \n");
            scanf("%d",&sayi2);
            if(sayi==sayi2)
                {
                    printf("tebrikler buldunuz !!! ");
                }
            else if (sayi>sayi2) printf("daha yuksek bir sayi giriniz :");
            else printf("daha dusuk bir sayi giriniz : ");
        }


    return 0;
}
