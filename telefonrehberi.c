#include <stdio.h>
#include <stdlib.h>

struct REHBER
{
    char kisiAdi[20];
    double telNo;
};

struct REHBER rehber[100];
int mevcutKisi=0;

struct REHBER kisiKaydet()
{
    struct REHBER yeniKisi;

    printf("Yeni kisinin ismi: ");
    scanf("%s",&yeniKisi.kisiAdi);
    printf("Yeni kisinin telefon numarasi: ");
    scanf("%lf",&yeniKisi.telNo);

    return yeniKisi;
}

void kisiSil()
{
    int silSecim, i;
    rehberGoruntule();

    if (mevcutKisi == 0)
    {
        printf("Rehberde kayitli kimse bulunmamaktadir, tekrar secim yapiniz!\n");
    }
    else
    {
        printf("\nSilmek istediginiz kisinin sira numarasini girin: ");
        scanf("%d", &silSecim);
        printf("\n");

        if (silSecim < 1 || silSecim > mevcutKisi)
        {
            printf("Hatali secim!\n");
        }
        else
        {
            printf("%s kisisi basariyla silindi!\n", rehber[silSecim - 1].kisiAdi);
            for (i = silSecim - 1; i < mevcutKisi - 1; i++)
            {
                rehber[i] = rehber[i + 1];
            }
            mevcutKisi--;
        }
    }
}

void rehberGoruntule()
{
	int i;
    for(i=0 ; i<mevcutKisi; i++)
    {
        printf("%d- Kisi adi: %s - Telefon numarasi: %2.lf\n",i+1,rehber[i].kisiAdi,rehber[i].telNo);
    }
}

int main()
{
    int secim;

    printf("--------------------\n");
    printf("1- Kisi Kaydet\n");
    printf("2- Kisi Sil\n");
    printf("3- Tum Rehberi Goruntule\n");
    printf("0- Cikis\n");
    printf("--------------------\n");

    printf("\nSeciminiz: ");
    scanf("%d",&secim);
    printf("\n");

    while(secim!=0)
    {
        if(secim==1)
        {
            struct REHBER yeniKisi = kisiKaydet();
            rehber[mevcutKisi] = yeniKisi;
            mevcutKisi++;
        }
        else if(secim==2)
        {
            kisiSil();
        }
        else if(secim==3)
        {
            rehberGoruntule();
        }
        else
        {
            printf("Hatali secim yaptiniz, lutfen menuden bir numara tuslayin!\n");
        }

        printf("\nSeciminiz: ");
        scanf("%d",&secim);
        printf("\n");
    }
    printf("\nProgram sonlandi!\n");

    return 0;
}

