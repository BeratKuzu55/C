#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int determinant_hesapla9_deger(int n,...)
{
    int determinant_degeri=0;
    va_list liste;
    va_start(liste,n);

    int matris[3][3],matris_sarrus[5][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           matris[i][j]=va_arg(liste,int);
           matris_sarrus[i][j]=matris[i][j];

        }
    }

    va_end(liste);

    for(int i=3;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            int a = matris[i-3][j];
            matris_sarrus[i][j]=a;

        }
    }


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%5d ",matris_sarrus[i][j]);
        }
        printf("\n");
    }

     int toplam1=0;
     int A1=1,A2=1,A3=1;
    for (int i=0,j=0;i<3&&j<3;i++,j++)
    {

         A1=A1*matris_sarrus[i][j];
         A2=A2*matris_sarrus[i+1][j];
         A3=A3*matris_sarrus[i+2][j];



    }
    toplam1=A1+A2+A3;
  //  printf(" toplam1 : %d",toplam1);

     int toplam2=0;
     int B1=1,B2=1,B3=1;
    for(int i=0,j=2;i<3&&j>-1;i++,j--)
    {

        B1=B1*matris_sarrus[i][j];
        B2=B2*matris_sarrus[i+1][j];
        B3=B3*matris_sarrus[i+2][j];//mantik hatasi var bunlarda


    }
    toplam2=B1+B2+B3;
   // printf(" toplam2 : %d ",toplam2);


     determinant_degeri = toplam1-toplam2;
    return determinant_degeri;
}


int main()
{
    printf("determinanti hesaplanmak uzere 3*3 tipindeki matrisin elemanlarini giriniz ");
    int x1,x2,x3,x4,x5,x6,x7,x8,x9;
    scanf("%d %d %d %d %d %d %d %d %d",&x1,&x2,&x3,&x4,&x5,&x6,&x7,&x8,&x9);

    int sonuc = determinant_hesapla9_deger(9,x1,x2,x3,x4,x5,x6,x7,x8,x9);
    printf("determinant sonucu : %d",sonuc);

    return 0;
}
