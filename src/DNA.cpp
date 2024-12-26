/**
 * @file        b221210049 numaralı öğrenci ödevi
 * @description bağlı listeler kullanarak gen,kromozom ve DNA işlemleri yapan program.
 * @course      1.öğretim A grubu
 * @assignment  ödev-1
 * @date        27.11.2024
 * @author      BATUHAN YILDIRIM--batuhan.yildirim8@ogr.sakarya.edu.tr
 */

#include "DNA.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> // std::string için gerekli

DNA::DNA() : ilk(nullptr) {}

DNA::~DNA()
{
    KromozomDugum *gec = ilk;
    while (gec != nullptr)
    {
        KromozomDugum *sil = gec;
        gec = gec->sonraki;
        delete sil->kromozom;
        delete sil;
    }
    // std::cout<<"DNA destructor basarili sekilde calisti"<<std::endl; Başarılı şekilde çalışıyor DENEME
}

void DNA::kromozomEkle(Liste *kromozom)
{
    KromozomDugum *newKromozomDugum = new KromozomDugum(kromozom);
    if (ilk == nullptr)
    {
        ilk = newKromozomDugum;
    }
    else
    {
        KromozomDugum *gec = ilk;
        while (gec->sonraki != nullptr)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = newKromozomDugum;
    }
}

Liste *DNA::kromozomGetir(int indeks)
{
    KromozomDugum *gec = ilk;
    int sayac = 0;
    while (gec != nullptr)
    {
        if (sayac == indeks)
        {
            return gec->kromozom;
        }
        gec = gec->sonraki;
        sayac++;
    }
    return nullptr;
}

void DNA::caprazlama(int indeks1, int indeks2)
{
    Liste *kromozom1 = kromozomGetir(indeks1);
    Liste *kromozom2 = kromozomGetir(indeks2);

    if (kromozom1 == nullptr || kromozom2 == nullptr)
    {
        std::cout << "Geçersiz kromozom indeksi girdiniz!" << std::endl;
        return;
    }

    // Kromozomların gen sayılarını al
    int uzunluk1 = kromozom1->uzunluk();
    int uzunluk2 = kromozom2->uzunluk();

    Dugum *gec1 = kromozom1->dugumGetir(0); // Kromozom1'in ilk genine git
    Dugum *gec2 = kromozom2->dugumGetir(0); // Kromozom2'nin ilk genine git

    Dugum *baslangic1 = kromozom1->dugumGetir(0); // Kromozom1'nin ilk genine git
    Dugum *baslangic2 = kromozom2->dugumGetir(0); // Kromozom2'nin ilk genine git

    // Kromozomların orta noktalarını bul
    int orta1 = uzunluk1 / 2;
    int orta2 = uzunluk2 / 2;

    // Yeni kromozomlar oluştur
    Liste *newKromozom1 = new Liste();
    Liste *newKromozom2 = new Liste();

    // Çaprazlama işlemi: Kromozomları eşleştir
    if (uzunluk1 % 2 != 0)
    { // Kromozom 1 tek sayılı
        gec1 = kromozom1->dugumGetir(0);
        for (int i = 0; i < orta1; i++)
        {
            newKromozom1->ekle(gec1->veri);
            gec1 = gec1->sonraki;
        }

        // uzunluk 2 kontrol noktası

        if (uzunluk2 % 2 != 0)
        {
            gec2 = kromozom2->dugumGetir(orta2 + 1); // Ortadaki gen hariç
            while (gec2 != baslangic2)
            { // dairesel olduğu için ilk gene kadar kontrol et
                newKromozom1->ekle(gec2->veri);
                gec2 = gec2->sonraki;
            }
        }
        else
        {
            gec2 = kromozom2->dugumGetir(orta2);
            while (gec2 != baslangic2)
            { // dairesel olduğu için ilk gene kadar kontrol et
                newKromozom1->ekle(gec2->veri);
                gec2 = gec2->sonraki;
            }
        }

        gec1 = kromozom1->dugumGetir(orta1 + 1); // Ortadaki gen hariç
        while (gec1 != baslangic1)
        { // dairesel olduğu için ilk gene kadar kontrol et
            newKromozom2->ekle(gec1->veri);
            gec1 = gec1->sonraki;
        }

        gec2 = kromozom2->dugumGetir(0);
        for (int i = 0; i < orta2; i++)
        {
            newKromozom2->ekle(gec2->veri);
            gec2 = gec2->sonraki;
        }
    }

    else
    { // Kromozom 1 çift sayılı
        gec1 = kromozom1->dugumGetir(0);
        for (int i = 0; i < orta1; i++)
        {
            newKromozom1->ekle(gec1->veri);
            gec1 = gec1->sonraki;
        }

        if (uzunluk2 % 2 != 0)
        {
            gec2 = kromozom2->dugumGetir(orta2 + 1);
            while (gec2 != baslangic2)
            { // dairesel olduğu için ilk gene kadar kontrol et
                newKromozom1->ekle(gec2->veri);
                gec2 = gec2->sonraki;
            }
        }
        else
        {
            gec2 = kromozom2->dugumGetir(orta2);
            while (gec2 != baslangic2)
            { // dairesel olduğu için ilk gene kadar kontrol et
                newKromozom1->ekle(gec2->veri);
                gec2 = gec2->sonraki;
            }
        }

        gec1 = kromozom1->dugumGetir(orta1);
        while (gec1 != baslangic1)
        { // dairesel olduğu için ilk gene kadar kontrol et
            newKromozom2->ekle(gec1->veri);
            gec1 = gec1->sonraki;
        }

        gec2 = kromozom2->dugumGetir(0);
        for (int i = 0; i < orta2; i++)
        {
            newKromozom2->ekle(gec2->veri);
            gec2 = gec2->sonraki;
        }
    }

    // Yeni kromozomları DNA'ya ekle
    kromozomEkle(newKromozom1);
    kromozomEkle(newKromozom2);

    std::cout << "Caprazlama islemi tamamlandi!" << std::endl;
}

void DNA::mutasyon(int kromozomIndeks, int genIndeks)
{ // seçili kromozomun genine X harfini yazıyoruz buda bize mutasyon işlemini yapmış oluyor
    Liste *kromozom = kromozomGetir(kromozomIndeks);
    if (kromozom == nullptr)
    {
        std::cout << "Gecersiz kromozom indeksi!" << std::endl;
        return;
    }

    Dugum *gen = kromozom->dugumGetir(genIndeks);
    if (gen != nullptr)
    {
        gen->veri = 'X';
    }
}

void DNA::yazdir()
{ // ilgili geni yazdırıyoruz bizden istenende o zaten
    KromozomDugum *gec = ilk;
    int indeks = 0;

    while (gec != nullptr)
    {
        gec->kromozom->yazdir();
        gec = gec->sonraki;
        indeks++;
    }
}

void DNA::otomatikIslemler(const std::string &islemlerDosyasi)
{
    std::ifstream dosya(islemlerDosyasi);
    if (!dosya.is_open())
    {
        std::cerr << "İslemler dosyasi acilamadi: " << islemlerDosyasi << std::endl;
        return;
    }

    std::string satir;
    while (std::getline(dosya, satir))
    {
        std::istringstream iss(satir);
        char islemTipi;
        int indeks1, indeks2;

        // Satırı işle
        iss >> islemTipi;

        if (islemTipi == 'C')
        {
            // Çaprazlama işlemi
            iss >> indeks1 >> indeks2;
            std::cout << "Caprazlama: Kromozom " << indeks1 << " ve Kromozom " << indeks2 << " arasinda caprazlama yapiliyor." << std::endl;
            caprazlama(indeks1, indeks2);
        }
        else if (islemTipi == 'M')
        {
            // Mutasyon işlemi
            iss >> indeks1 >> indeks2;
            std::cout << "Mutasyon: Kromozom " << indeks1 << " ve Gen " << indeks2 << " uzerinde mutasyon yapiliyor." << std::endl;
            mutasyon(indeks1, indeks2);
        }
    }

    dosya.close();
    std::cout << "Tum islemler tamamlandi!" << std::endl;
}
