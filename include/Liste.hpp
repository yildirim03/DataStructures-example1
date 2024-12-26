/**
* @file        b221210049 numaralı öğrenci ödevi
* @description bağlı listeler kullanarak gen,kromozom ve DNA işlemleri yapan program.
* @course      1.öğretim A grubu
* @assignment  ödev-1
* @date        27.11.2024
* @author      BATUHAN YILDIRIM--batuhan.yildirim8@ogr.sakarya.edu.tr
*/

#ifndef LISTE_HPP
#define LISTE_HPP

#include "Dugum.hpp"

class Liste {
private:
    Dugum* ilk; // Listenin ilk düğümüne işaretçi

public:
    Liste();            // Yapıcı: Bağlı listeyi başlatır (ilk düğümü nullptr olarak ayarlar)
    ~Liste();           // Yıkıcı: Tüm düğümleri serbest bırakarak belleği temizler
    void ekle(char veri); // Yeni bir gen (düğüm) ekler (listenin sonuna ekleme yapar)
    Dugum* dugumGetir(int sira); // Belirtilen sıradaki düğümü döndürür
    void yazdir();       // Listenin en küçük (genini) bulup ekrana yazdırır
    int uzunluk();       // caprazlama işleminde kromozomun uzunluğunu bulma ve orta noktasını bulma 
};

#endif
