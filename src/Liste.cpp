/**
* @file        b221210049 numaralı öğrenci ödevi
* @description bağlı listeler kullanarak gen,kromozom ve DNA işlemleri yapan program.
* @course      1.öğretim A grubu
* @assignment  ödev-1
* @date        27.11.2024
* @author      BATUHAN YILDIRIM--batuhan.yildirim8@ogr.sakarya.edu.tr
*/

#include "Liste.hpp"
#include <iostream>

Liste::Liste() {
    ilk = nullptr;  // Başlangıçta liste boştur
}

Liste::~Liste() {
    Dugum* gec = ilk;
    if (gec != nullptr) {
        do {
            Dugum* sil = gec;
            gec = gec->sonraki;
            delete sil;
        } while (gec != ilk);  // Daireyi döngüyle terk et
    }
     //std::cout<<"Liste destructor basarili sekilde calisti"<<std::endl;  Başarılı şekilde çalışıyor DENEME

}

void Liste::ekle(char veri) {
    Dugum* newDugum = new Dugum(veri);

    if (ilk == nullptr) { // Liste boşsa
        ilk = newDugum;
        ilk->onceki = ilk;
        ilk->sonraki = ilk;
    } else { // Liste boş değilse
        Dugum* gec = ilk;
        while (gec->sonraki != ilk) {  // Son düğüme kadar git
            gec = gec->sonraki;
        }
        gec->sonraki = newDugum;
        newDugum->onceki = gec;
        newDugum->sonraki = ilk;
        ilk->onceki = newDugum;
    }
}

Dugum* Liste::dugumGetir(int sira) {
    Dugum* gec = ilk;
    int indeks = 0;
    while (gec != nullptr) {
        if (indeks == sira) {
            return gec;
        }

        gec = gec->sonraki;
        indeks++;
    }
    return nullptr;
}


void Liste::yazdir() {
    if (ilk == nullptr) return;  // Liste boşsa hiçbir şey yapma

    Dugum* gec = ilk->onceki;  // Sağdan sola doğru tarama yapmak için son düğümden başla
    char ilkGen = ilk->veri;   // İlk genin değerini al
    char yazilacakGen = ilkGen; // Varsayılan olarak ilk gen yazılacak

    // Sağdan sola doğru tüm düğümleri tara
    do {
        if (gec->veri < ilkGen) {  // Eğer ilk genden daha küçük bir gen bulursak
            yazilacakGen = gec->veri;  // Bu gen yazılacak gen olur
            break;  // Daha fazla kontrol yapmaya gerek yok
        }
        gec = gec->onceki;  // Bir önceki düğüme geç
    } while (gec != ilk);  // Baştan sona döngüyü tamamla

    // Belirlenen gen yazdırılır
    std::cout << yazilacakGen <<" ";
}


 /* TÜM KROMOZOMLARIN GENLERİNİ GÖSTEREN FONKSİYONUM
void Liste::yazdir()
{
    Dugum* gec = ilk;
    do{
        std::cout << gec->veri << " ";
        gec = gec->sonraki;
    }while (gec != ilk);

    std::cout << std::endl;
       
}
*/


int Liste::uzunluk() {
    if (ilk == nullptr) return 0; // Liste boşsa uzunluk 0
    int uzunluk = 1;
    Dugum* gec = ilk;
    while (gec->sonraki != ilk) { // Dairesel liste olduğundan, ilk düğüme gelene kadar döneriz
        uzunluk++;
        gec = gec->sonraki;
    }
    return uzunluk;
}

