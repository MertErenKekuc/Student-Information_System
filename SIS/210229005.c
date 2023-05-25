#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//MERT EREN KEKÜÇ
//21022905

struct Ogrenci{
    char isim[40];
    char soyisim[40];
    char bolum[40];
    int numara;
    char sifre[40];
    int akts;
    int mevcutAkts;
};

struct OgretimUyesi{
    char isim[40];
    char soyisim[40];
    char kullaniciAdi[40];
    char sifre[40];
};

struct Memur{
    char isim[40];
    char soyisim[40];
    char kullaniciAdi[40];
    char sifre[40];
};

struct Admin{
    char isim[40];
    char soyisim[40];
    char kullaniciAdi[40];
    char sifre[40];
};


void OgrenciMenusu();
void MemurEkleme();
void OgretimUyesiMenusu();
void OgretimUyesiEkleme();
void AdminEkleme();
void MemurMenusu();
void AdminMenusu();
void Notlar();
void DersSecimi(int numara);
void OgrenciBelgesi();
void NotGirisi();
void OgrenciEkleme();
void DersAcma();
struct Ogrenci OgrenciHesabiAcma();
struct Memur MemurHesabiAcma();
struct OgretimUyesi OgretimUyesiHesabiAcma();
struct Admin AdminHesabiAcma();
int dosyasatirSayisi(char dosyaIsmi[]);
int notHesaplama(int Vize, int Final);
int ogrenciaktsKontrol(int girisNumarasi);



int main()
{
    int admin=dosyasatirSayisi("Admin.txt");
    if (admin == 0)
    {
        AdminEkleme();
    }
    int giris;
do
{
    printf("1:Ogrenci Menusu \n2:Ogretim Uyesi Menusu \n3:Memur Menusu \n4:Admin Menusu\n");
    printf("Sayi Seciniz : ");
    scanf("%d",&giris);

    switch(giris)
    {
        case 0:
        printf("Program sonlandirildi");
    break;
        case 1:
        OgrenciMenusu();
    break;
        case 2:
        OgretimUyesiMenusu();
    break;
        case 3:
        MemurMenusu();
    break;
        case 4:
        AdminMenusu();
    break;
    }

}while(giris!=0);

    return 0;
}


void OgrenciMenusu()
{
        char isim[40],soyisim[40],bolum[40],sifre[40];
        int numara,akts,mevcutAkts;
        int secim;
        int girisNumarasi;
        char girisSifresi[40];
        int flag =0;
    while(1)
    {
        FILE *dosya=fopen("Ogrenciler.txt","r");


        printf("Numaranizi giriniz :");
        scanf("%d",&girisNumarasi);
        printf("Sifrenizi giriniz :");
        scanf(" %s",girisSifresi);
        while (fscanf(dosya, "%s %s %s %d %s %d %d",isim,soyisim,bolum,&numara,sifre,&akts,&mevcutAkts) != EOF)
        {
            if ((strcmp(girisSifresi,sifre) == 0) && girisNumarasi == numara)
            {
                printf("Giris yapildi\n");
                flag = 1;
                break;
            }

        }
        if (flag == 1)
        {
            break;
        }
        fclose(dosya);
        if (flag == 0)
        {
            printf("Yanlis kullanici ismi veya sifre\n");
            continue;
        }
    }
    do
    {
        printf("\n0:Cikis yap\n1:Notlar \n2:Ders Secimi \n3:Ogrenci Belgesi\n");
        scanf("%d",&secim);
        switch(secim)
        {
            case 0:
            printf("Cikis yapildi\n");
        break;
            case 1:
            Notlar(numara);
        break;
            case 2:
            if (akts >= 20)
            {
                printf("akts = %d akts oldugu icin daha fazla ders alinamaz",akts);
                break;
            }
            DersSecimi(numara);
        break;
            case 3:
            OgrenciBelgesi(numara);
        break;
        }
    }while(secim != 0);
}

void OgretimUyesiMenusu()
{
     char girisKullaniciAdi[40];
     char girisSifresi[40];
     char isim[40], soyisim[40], kullaniciAdi[40], sifre[40];
     int flag=0;
     while(1)
    {
        FILE *dosya=fopen("OgretimUyeleri.txt","r");

        printf("Kullanici adinizi giriniz :");
        scanf(" %s",girisKullaniciAdi);
        printf("Sifrenizi giriniz :");
        scanf(" %s",girisSifresi);
        while (fscanf(dosya, "%s %s %s %s",isim,soyisim,kullaniciAdi,sifre) != EOF)
        {
            if ((strcmp(girisSifresi,sifre) == 0) && (strcmp(girisKullaniciAdi,kullaniciAdi) == 0))
            {
                printf("Giris yapildi\n");
                flag = 1;
                break;
            }

        }
        if (flag == 1)
        {
            break;
        }
        fclose(dosya);
        if (flag == 0)
        {
            printf("Yanlis kullanici ismi veya sifre\n");
            continue;
        }
    }
    int secim;
    printf("\n0:Cikis yap\n1: Not Girisi\n");
    scanf("%d",&secim);
    switch(secim)
    {
        case 1:
        NotGirisi();
    break;
    }
}

void MemurMenusu()
{
     char girisKullaniciAdi[40];
     char girisSifresi[40];
     char isim[40], soyisim[40], kullaniciAdi[40], sifre[40];
     int flag=0;
     while(1)
    {
        FILE *dosya=fopen("Memurlar.txt","r");


        printf("Kullanici adinizi giriniz :");
        scanf(" %s",girisKullaniciAdi);
        printf("Sifrenizi giriniz :");
        scanf(" %s",girisSifresi);
        while (fscanf(dosya, "%s %s %s %s",isim,soyisim,kullaniciAdi,sifre) != EOF)
        {
            if ((strcmp(girisSifresi,sifre) == 0) && (strcmp(girisKullaniciAdi,kullaniciAdi) == 0))
            {
                printf("Giris yapildi\n");
                flag = 1;
                break;
            }

        }
        if (flag == 1)
        {
            break;
        }
        fclose(dosya);
        if (flag == 0)
        {
            printf("Yanlis kullanici ismi veya sifre\n");
            continue;
        }
    }
    int secim;
do
{
    printf("\n0: Cikis yap\n1: Ogrenci Ekleme\n2: Ders Acma\n");
    scanf("%d",&secim);
    switch(secim)
    {
        case 0:
        printf("Cikis yapildi\n");
    break;
        case 1:
        OgrenciEkleme();
    break;
        case 2:
        DersAcma();
    break;

    }
}while(secim!=0);

}

void AdminMenusu()
{
     char girisKullaniciAdi[40];
     char girisSifresi[40];
     char isim[40], soyisim[40], kullaniciAdi[40], sifre[40];
     int flag=0;
     while(1)
    {
        FILE *dosya=fopen("Admin.txt","r");


        printf("Kullanici adinizi giriniz :");
        scanf(" %s",girisKullaniciAdi);
        printf("Sifrenizi giriniz :");
        scanf(" %s",girisSifresi);
        while (fscanf(dosya, "%s %s %s %s",isim,soyisim,kullaniciAdi,sifre) != EOF)
        {
            if ((strcmp(girisSifresi,sifre) == 0) && (strcmp(girisKullaniciAdi,kullaniciAdi) == 0))
            {
                printf("Giris yapildi\n");
                flag = 1;
                break;
            }

        }
        if (flag == 1)
        {
            break;
        }
        fclose(dosya);
        if (flag == 0)
        {
            printf("Yanlis kullanici ismi veya sifre\n");
            continue;
        }
    }
    int secim;
do
{
    printf("\n0: Cikis yap\n1: Memur Ekleme\n2: Ogretim Uyesi Ekleme");
    scanf("%d",&secim);

    switch(secim)
    {
        case 0:
        printf("Cikis yapildi\n");
    break;
        case 1:
        MemurEkleme();
    break;
        case 2:
        OgretimUyesiEkleme();
    }
}while(secim!=0);

}

struct Ogrenci OgrenciHesabiAcma(char isim[], char soyisim[], char bolum[], int numara, char sifre[], int akts, int mevcutAkts)
{
    struct Ogrenci ogrenci;
    strcpy(ogrenci.isim,isim);
    strcpy(ogrenci.soyisim,soyisim);
    strcpy(ogrenci.bolum,bolum);
    ogrenci.numara=numara;
    ogrenci.akts=akts;
    ogrenci.mevcutAkts=mevcutAkts;
    strcpy(ogrenci.sifre,sifre);

    return ogrenci;
}

struct Memur MemurHesabiAcma(char isim[], char soyisim[], char kullaniciAdi[], char sifre[])
{
    struct Memur memur;
    strcpy(memur.isim,isim);
    strcpy(memur.soyisim,soyisim);
    strcpy(memur.kullaniciAdi,kullaniciAdi);
    strcpy(memur.sifre,sifre);

    return memur;
}

struct OgretimUyesi OgretimUyesiHesabiAcma(char isim[], char soyisim[], char kullaniciAdi[], char sifre[])
{
    struct OgretimUyesi ogretimuyesi;
    strcpy(ogretimuyesi.isim,isim);
    strcpy(ogretimuyesi.soyisim,soyisim);
    strcpy(ogretimuyesi.kullaniciAdi,kullaniciAdi);
    strcpy(ogretimuyesi.sifre,sifre);

    return ogretimuyesi;
}

struct Admin AdminHesabiAcma(char isim[], char soyisim[], char kullaniciAdi[], char sifre[])
{
    struct Admin admin;
    strcpy(admin.isim,isim);
    strcpy(admin.soyisim,soyisim);
    strcpy(admin.kullaniciAdi,kullaniciAdi);
    strcpy(admin.sifre,sifre);

    return admin;
}

int notHesaplama(int Vize, int Final)
{
    int Ortalama;
    Ortalama=(Vize+Final)/2;

    return Ortalama;
}

// Öðrencinin notlarýný görme fonksiyonu
void Notlar(int girisNumarasi)
{
    int numara,Vize,Final,Ortalama;
    char dersIsmi[40],ogretimUyesiIsmi[40],geciciDersIsmi[40];
    FILE *dosya=fopen("Dersler.txt","r");
    while (fscanf(dosya, "%s %s",dersIsmi,ogretimUyesiIsmi) != EOF)
    {
        strcpy(geciciDersIsmi,dersIsmi);
        strcat(dersIsmi,".txt");
        FILE *ders=fopen(dersIsmi,"r");
        fscanf(ders, "%s %s",dersIsmi,ogretimUyesiIsmi);
        while (fscanf(ders, "%d %d %d %d",&numara,&Vize,&Final,&Ortalama) != EOF)
        {
            if(numara==girisNumarasi)
            {
                printf("%s Dersinin Notlari\nVize=%d\nFinal=%d\nOrtalama=%d",geciciDersIsmi,Vize,Final,Ortalama);
            }
        }
        fclose(ders);
    }
    fclose(dosya);
}

void DersSecimi(int numara)
{
    char dersIsmi[40];
    char dosyaIsmi[40];
    printf("Istediginiz dersi girin :");
    scanf(" %s",dersIsmi);

    strcpy(dosyaIsmi,dersIsmi);
    strcat(dosyaIsmi,".txt");
    FILE *dosya=fopen(dosyaIsmi,"a");
    fprintf(dosya,"%d %d %d %d\n",numara,0,0,0);
    fclose(dosya);
}

void OgrenciBelgesi(int girisNumarasi)
{
    char isim[40],soyisim[40],sifre[40],bolum[40];
    int mevcutakts,akts,numara;
    FILE *dosya=fopen("Ogrenciler.txt","r");
    FILE *ogrenciBelgesi=fopen("OgrenciBelgesi.txt","w");
    while (fscanf(dosya, "%s %s %s %d %s %d %d",isim,soyisim,bolum,&numara,sifre,&akts,&mevcutakts) != EOF)
        {
            if(numara==girisNumarasi)
            {
                fprintf(ogrenciBelgesi,"isim=%s \nsoyisim=%s \nnumara=%d \nbolum=%s ",isim,soyisim,numara,bolum);
            }

        }
    fclose(dosya);
    fclose(ogrenciBelgesi);
}

void NotGirisi()
{
    char dersIsmi[40];
    char dosyaIsmi[40];
    char ogretimUyesiIsmi[40];
    int numara,Vize,Final,Ortalama,girisNumarasi;
    printf("Dersi girin \n");
    scanf(" %s",dersIsmi);
    printf("Ogrencinin numarasini girin \n");
    scanf("%d",&girisNumarasi);
    strcpy(dosyaIsmi,dersIsmi);
    strcat(dosyaIsmi,".txt");
    FILE *dosya=fopen(dosyaIsmi,"r");
    FILE *dosya2=fopen("tempders.txt","w");

    fscanf(dosya, "%s %s",dersIsmi,ogretimUyesiIsmi);
    fprintf(dosya2,"%s %s\n",dersIsmi,ogretimUyesiIsmi);

    while (fscanf(dosya, "%d %d %d %d",&numara,&Vize,&Final,&Ortalama) != EOF)
    {
        if(numara==girisNumarasi)
        {
            printf("Ogrencinin vize notunu giriniz ");
            scanf("%d",&Vize);
            printf("Ogrencinin final notunu giriniz ");
            scanf("%d",&Final);
            Ortalama = notHesaplama(Vize,Final);
        }

        fprintf(dosya2,"%d %d %d %d\n",numara,Vize,Final,Ortalama);

    }
    fclose(dosya);
    fclose(dosya2);
    remove(dosyaIsmi);
    rename("tempders.txt", dosyaIsmi);

}

void OgrenciEkleme()
{
    int ogrenciSayisi = dosyasatirSayisi("Ogrenciler.txt");
    if (ogrenciSayisi >= 100)
    {
        printf("%d ogrenci bulunuyor daha fazla ogrenci eklenemez!",ogrenciSayisi);
        return;
    }
    FILE *dosya=fopen("Ogrenciler.txt", "a");
    char isim[40];
    char soyisim[40];
    char bolum[40];
    int numara,akts;
    char sifre[40];


    printf("Isim Giriniz : ");
    scanf(" %s",isim);
    printf("Soyisim Giriniz : ");
    scanf(" %s",soyisim);
    printf("Bolum Giriniz : ");
    scanf(" %s",bolum);
    printf("Numara Giriniz : ");
    scanf("%d",&numara);
    printf("Sifre Giriniz : ");
    scanf(" %s",sifre);

    struct Ogrenci ogrenci = OgrenciHesabiAcma(isim, soyisim, bolum, numara, sifre, 0, 0);
    fprintf(dosya,"%s %s %s %d %s %d %d\n",ogrenci.isim,ogrenci.soyisim,ogrenci.bolum,ogrenci.numara,ogrenci.sifre,ogrenci.akts,ogrenci.mevcutAkts);
    fclose(dosya);

}

void MemurEkleme()
{
    int memurSayisi = dosyasatirSayisi("Memurlar.txt");
    if (memurSayisi > 0)
    {
        printf("%d memur bulunuyor daha fazla memur eklenemez!",memurSayisi);
        return;
    }
    FILE *dosya=fopen("Memurlar.txt", "a");
    char isim[40];
    char soyisim[40];
    char sifre[40];
    char kullaniciAdi[40];

    printf("Isim Giriniz : ");
    scanf(" %s",isim);
    printf("Soyisim Giriniz : ");
    scanf(" %s",soyisim);
    printf("Kullanici Adi Giriniz : ");
    scanf(" %s",kullaniciAdi);
    printf("Sifre Giriniz : ");
    scanf(" %s",sifre);

    struct Memur memur = MemurHesabiAcma(isim, soyisim, kullaniciAdi, sifre);
    fprintf(dosya,"%s %s %s %s\n",memur.isim,memur.soyisim,memur.kullaniciAdi,memur.sifre);
    fclose(dosya);

}

void OgretimUyesiEkleme()
{
    int ogretimuyesiSayisi = dosyasatirSayisi("OgretimUyeleri.txt");
    if (ogretimuyesiSayisi >= 4)
    {
        printf("%d ogretim uyesi bulunuyor daha fazla ogretim uyesi eklenemez!",ogretimuyesiSayisi);
        return;
    }
    FILE *dosya=fopen("OgretimUyeleri.txt", "a");
    char isim[40];
    char soyisim[40];
    char sifre[40];
    char kullaniciAdi[40];

    printf("Isim Giriniz : ");
    scanf(" %s",isim);
    printf("Soyisim Giriniz : ");
    scanf(" %s",soyisim);
    printf("Kullanici Adi Giriniz : ");
    scanf(" %s",kullaniciAdi);
    printf("Sifre Giriniz : ");
    scanf(" %s",sifre);

    struct OgretimUyesi ogretimuyesi = OgretimUyesiHesabiAcma(isim, soyisim, kullaniciAdi, sifre);
    fprintf(dosya,"%s %s %s %s\n",ogretimuyesi.isim,ogretimuyesi.soyisim,ogretimuyesi.kullaniciAdi,ogretimuyesi.sifre);
    fclose(dosya);

}

void AdminEkleme()
{
    printf("Programda admin yoktur baslangicta admin hesabi olusturulacaktir\n");

    FILE *dosya=fopen("Admin.txt", "a");
    char isim[40];
    char soyisim[40];
    char sifre[40];
    char kullaniciAdi[40];

    printf("Isim Giriniz : ");
    scanf(" %s",isim);
    printf("Soyisim Giriniz : ");
    scanf(" %s",soyisim);
    printf("Kullanici Adi Giriniz : ");
    scanf(" %s",kullaniciAdi);
    printf("Sifre Giriniz : ");
    scanf(" %s",sifre);

    struct Admin admin = AdminHesabiAcma(isim, soyisim, kullaniciAdi, sifre);
    fprintf(dosya,"%s %s %s %s\n",admin.isim,admin.soyisim,admin.kullaniciAdi,admin.sifre);
    fclose(dosya);
}


void DersAcma()
{
    char dersIsmi[40];
    char dosyaIsmi[40];
    char ogretimuyesiIsmi[40];

    FILE *dosya=fopen("Dersler.txt", "a");
    printf("Acmak istediginiz dersin adini yazin :");
    scanf(" %s",dersIsmi);
    printf("Ogretim uyesinin kullanici adini girin :");
    scanf(" %s",ogretimuyesiIsmi);

    fprintf(dosya,"%s %s\n",dersIsmi,ogretimuyesiIsmi);
    fclose(dosya);

    strcpy(dosyaIsmi,dersIsmi);
    strcat(dosyaIsmi,".txt");
    dosya=fopen(dosyaIsmi,"w");
    fprintf(dosya,"%s %s\n",dersIsmi, ogretimuyesiIsmi);
    fclose(dosya);
}

//Öðrenci sayisinin maksimum 100 olmasi için
int dosyasatirSayisi(char dosyaIsmi[])
{
    FILE *dosya;
    int satirSayisi = 0;
    char chr;

    dosya = fopen(dosyaIsmi, "r");
    chr = getc(dosya);
    while (chr != EOF)
    {
        if (chr == '\n')
        {
            satirSayisi=satirSayisi+1;
        }
        chr = getc(dosya);
    }
    fclose(dosya);
    return satirSayisi;
}
