#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
const int trigram_size=3;
float frekans_bulma_2(int sayac_degeri,float metin_uzunlugu);///   frekansin bu sekilde bulundugunu varsayarak tanimladim     ///
double frekanshesabi(int saydir,int metin_uzunlugu);
void buyukharf_to_kucukharf(char str[]);// tum harfleri kucuk harfe donusturen fonksiyon

const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};

const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};// "\0" karakteri de var
const char languages[2][8]={"english", "german"};

//�ngilizce dilinin frekans de�erleri
 const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
 //Almanca dilinin frekans de�erleri
 const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };


float calculated_frequencies[20];
float distances [2]={0,0};


void filter_str(char str[]);
void calculate_frequencies_bi(char str[]);
void calculate_frequencies_tri(char str[]);
void calculate_distances();
void detect_lang();


char girilen_metin[];
int main()
{
    printf("dil kontrolu icin metin giriniz :");
    gets(girilen_metin);
    filter_str(girilen_metin);
    puts(girilen_metin);
    printf("*************************************");
    buyukharf_to_kucukharf(girilen_metin);

    calculate_frequencies_bi(girilen_metin);
    calculate_frequencies_tri(girilen_metin);
    calculate_distances();
    //detect_lang(); calculate_distances fonksiyonunda bu islem de yapıldı

	return 0;
}

void filter_str(char str[])
{
  for(int i=0;i<strlen(str);i++)
	{    //for ile dizi elemanlari geziliyor
       		 if((str[i]<65||(str[i]>90&&str[i]<97)||str[i]>122))
			{    //ASCII tabloda A-Z ve a-z araliginda olmayan karakterler icin if True olur
                str[i]=32;  //boşluk karakterinin sayisal degeri ataniyor
            }
    }
}


void buyukharf_to_kucukharf(char str[])
{
    //  A harfi ascii kodu 65 a harfi ascii kodu 97 aralarindaki fark 32 diger harflerde de durum ayni bu bilgiyi kullanmaya calisacagim
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>=65&&str[i]<=90)
        {
            str[i]+=32;
        }

    }
}


  void calculate_frequencies_bi(char str[])
    {
int th_sayac=0,he_sayac=0,in_sayac=0,er_sayac=0,an_sayac=0,en_sayac=0,ch_sayac=0,de_sayac=0,ei_sayac=0,te_sayac=0;
int bulunan_sayi=0;
        printf("%d",strlen(str));
        for(int i=0;i<strlen(str)-2+1;i++)
        {
            th_sayac+=bigram_sayisi(str,i,0);//yazdigim bigram_sayisi fonksiyonu her iterasyonda aranan bigram in kontrolunu yapacak
            he_sayac+=bigram_sayisi(str,i,1);//bigram varsa 1 degerini donecek ve bu bir degeri aranan bigram in sayac degerine eklenecek
            in_sayac+=bigram_sayisi(str,i,2);
            er_sayac+=bigram_sayisi(str,i,3);
            an_sayac+=bigram_sayisi(str,i,4);
            en_sayac+=bigram_sayisi(str,i,5);
            ch_sayac+=bigram_sayisi(str,i,6);
            de_sayac+=bigram_sayisi(str,i,7);
            ei_sayac+=bigram_sayisi(str,i,8);
            te_sayac+=bigram_sayisi(str,i,9);


        }

          printf("\n th sayisi :%d",th_sayac);
          printf("\n he sayisi :%d",he_sayac);
          printf("\n in sayisi :%d",in_sayac);
          printf("\n er sayisi :%d",er_sayac);
          printf("\n an sayisi :%d",an_sayac);
          printf("\n en sayisi :%d",en_sayac);
          printf("\n ch sayisi :%d",ch_sayac);
          printf("\n de sayisi :%d",de_sayac);
          printf("\n ei sayisi :%d",ei_sayac);
          printf("\n te sayisi :%d",te_sayac);

         float metin_uzunlugu=strlen(str);/*metin uzunlugunu float olarak tanimlama
         sebebim : int olarak tanimlasaydim frekans_bulma_2 fonksiyonunda
          int/int yaptigimiz zaman virgulden sonraki sayilarin 0 gelmesi*/
         float frekans_th=frekans_bulma_2(th_sayac,metin_uzunlugu);
         float frekans_he=frekans_bulma_2(he_sayac,metin_uzunlugu);
         float frekans_in=frekans_bulma_2(in_sayac,metin_uzunlugu);
         float frekans_er=frekans_bulma_2(er_sayac,metin_uzunlugu);
         float frekans_an=frekans_bulma_2(an_sayac,metin_uzunlugu);
         float frekans_en=frekans_bulma_2(en_sayac,metin_uzunlugu);
         float frekans_ch=frekans_bulma_2(ch_sayac,metin_uzunlugu);
         float frekans_de=frekans_bulma_2(de_sayac,metin_uzunlugu);
         float frekans_ei=frekans_bulma_2(ei_sayac,metin_uzunlugu);
         float frekans_te=frekans_bulma_2(te_sayac,metin_uzunlugu);
         printf("\nth frekansi : %f ",frekans_th);
          printf("\nhe frekansi : %f ",frekans_he);
           printf("\nin frekansi : %f ",frekans_in);
            printf("\ner frekansi : %f ",frekans_er);
             printf("\nan frekansi : %f ",frekans_an);
              printf("\nen frekansi : %f ",frekans_en);
               printf("\nch frekansi : %f ",frekans_ch);
                printf("\nde frekansi : %f ",frekans_de);
                 printf("\nei frekansi : %f ",frekans_ei);
                  printf("\nte frekansi : %f ",frekans_te);
         calculated_frequencies[0]=frekans_th;
         calculated_frequencies[1]=frekans_he;
         calculated_frequencies[2]=frekans_in;
         calculated_frequencies[3]=frekans_er;
         calculated_frequencies[4]=frekans_an;
         calculated_frequencies[5]=frekans_en;
         calculated_frequencies[6]=frekans_ch;
         calculated_frequencies[7]=frekans_de;
         calculated_frequencies[8]=frekans_ei;
         calculated_frequencies[9]=frekans_te;
                  /*   bu kisma kadar kullanicidan metin aldik metindeki harf harici karakterleri temizledik
                   bigramlari aradik ve hangi bigramdan kac adet oldugunu bulduk daha sonrarinda dogru oldugunu
                   varsaydigimiz formul ile frekans hesapladik frekans degerlerini calculated_frequencies dizisine
                   ekledik simdi ise bulunan frekansin hangi dile daha yakin oldugunun kontrolunu yapmaya calisacagiz      */



    }

    int bigram_sayisi(char str[],int i,int matrix_bigram_index_1)
    {    //bu fonksiyon aradigimiz bigram i bulursa 1 degerini cagirildigi yere donecek
            int j,sayac=0;
            for(j=0;j<2;j++)
            {

                if(str[i+j]==matrix_bigram_strings[matrix_bigram_index_1][j])
                {

                }
                else break;

            }
            if(j==2)
            {
                sayac++;
            }
            return sayac;

    }


    float frekans_bulma_2(int sayac_degeri,float metin_uzunlugu)
    {
       float sonuc=(sayac_degeri*100*2)/metin_uzunlugu; //* 2 dememin sebebi : "th" metnini girersek *2 den once 1*100/2 = 50 cikardi
       //ancak bu metinde th frekansi 100 olmali
        return sonuc;
    }




void calculate_frequencies_tri(char str[]){ // metindeki trigram stringlerin sayisini bulan fonksiyon
    int trigram_sayisi[10]={0}; // 10 tane olan trigram stringlerin bulunma sayisini tutacagimiz dizi
    for(int x=0;x<10;x++){// trigram stringlerini sirayla aramak icin for dongumuz
        for(int i=0;i<=strlen(str)-trigram_size;i++){ //metinimizin icinde arama yapmak icin for dongumuz //"str_size-trigram_size" ifadesi metinimizin disinda aramna yapilmamasi icin
            int karakter_eslesme=0; //aranan karakterlerin eslesme durumunu bu degiskende tutacaz
            for(int y=0;y<trigram_size;y++){ // trigram karakterlerinde arama yapmak icin for donumuz
                if(matrix_trigram_strings[x][y]==str[i+y] // aranan trigram karakterinin  metinimizin karakterleri eslesiyor  mu
                   ||matrix_trigram_strings[x][y]-32==str[i+y]){ //aranan trigram karakterinin buyuk harfi ile eslesiyor  mu
                    karakter_eslesme++; // buyuk veya kucuk harf fark etmek sizin eslesme olursa degiskenimiz 1 artiyor
                    if(karakter_eslesme==trigram_size){ // karakter eslesmesi trigram boyutu kadar olursa yani tamamen eslesirse
                        trigram_sayisi[x]++; //aranan trigram sayisi 1 arttiriliyor
                    }
                }
            }
        }
    }
    printf("\n\n");
   for(int i=0;i<10;i++){
        for(int j=0;j<trigram_size;j++){
            printf("%c",matrix_trigram_strings[i][j]);
        }
        printf(" %d adet var.\n",trigram_sayisi[i]);

    }
    for(int i=0;i<10;i++){
        for(int j=0;j<trigram_size;j++){
            printf("%c",matrix_trigram_strings[i][j]);
        }
        float sonuc = frekanshesabi(trigram_sayisi[i],strlen(str));
        printf(" frekansi : %f\n",sonuc);

        calculated_frequencies[i+10]=sonuc;


    }
}

    double frekanshesabi(int saydir,int metin_uzunlugu)
    {

        double sonuc;

        sonuc=(float)saydir*3*100/metin_uzunlugu; //* 3 dememin sebebi :
        //"the" metnini girersek *2 den once 1*100/3 = 50 cikardi
       //ancak bu metinde the frekansi 100 olmali
        return sonuc;
    }


    void calculate_distances()
    {
         float eng_toplam_mesafenin_karesi=0; float germ_toplam_mesafenin_karesi=0;
       // calculated_frequencies[],frequency_eng[],frequency_germ[]


       for (int i=0;i<20;i++)
       {
          // printf(" \n frequency_eng[%d]: %f frequency_germ[%d]: %f  calc_freq[%d]: %f ",i,frequency_eng[i],i,frequency_germ[i],i,calculated_frequencies[i]);
       }

        for(int i=0;i<20;i++)
        {

             eng_toplam_mesafenin_karesi+=pow((frequency_eng[i]-calculated_frequencies[i]),2);
             germ_toplam_mesafenin_karesi+=pow((frequency_germ[i]-calculated_frequencies[i]),2);

        }
        float eng_toplam_mesafe=sqrt(eng_toplam_mesafenin_karesi);
        float germ_toplam_mesafe=sqrt(germ_toplam_mesafenin_karesi);

        printf("\n\neng_toplam_mesafe : %f , germ_toplam_mesafe : %f ",eng_toplam_mesafe,germ_toplam_mesafe);


        if(eng_toplam_mesafe<germ_toplam_mesafe)
            printf("\n\nGirilen metin Ingilizce dilindedir\n\n ");
        else if(eng_toplam_mesafe>germ_toplam_mesafe)
            printf("\n\nGirilen metin Almanca dilindedir\n\n");
        else if(eng_toplam_mesafe==germ_toplam_mesafe)
            printf("\n\nMetin 2 farkli dilde ");


    }
