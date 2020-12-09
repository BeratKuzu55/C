#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
     // girilen karakter harf mi:

    char karakter;
    printf("karakter analizi icin lutfen tuslama yapiniz : \n");
    scanf("%c",&karakter);

    // bu islemler ascii tablosuna gore yapiliyor 65,90 sayisi harflerin klayyedeki
    //karsiliklari

    if (karakter >= 65 && karakter <= 90) printf("buyuk bir harf girildi : \n");
    else if (karakter >= 97 && karakter <= 122) printf("kucuk bir harf girdiniz : \n");
    else printf("girdiginiz karakter harf degildir.");

    //BURADA 65 YERİNE 'A' 90 YERİNE 'Z' DE GİREBİLİRDİK SONUCTA DİGER
    //HARFLER DE İKİSİNİN ARASINDA




    return 0;
}
