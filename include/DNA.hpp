/**
* @file        b221210049 numaralı öğrenci ödevi
* @description bağlı listeler kullanarak gen,kromozom ve DNA işlemleri yapan program.
* @course      1.öğretim A grubu
* @assignment  ödev-1
* @date        27.11.2024
* @author      BATUHAN YILDIRIM--batuhan.yildirim8@ogr.sakarya.edu.tr
*/

#ifndef DNA_HPP
#define DNA_HPP

#include "Liste.hpp"
#include<string> // std::string kullanımı için gerekli


class DNA {
private:
    struct KromozomDugum { // DNA'yı oluşturan bağlı liste düğümü
        Liste* kromozom; // Bir kromozomu temsil eden Liste
        KromozomDugum* sonraki; // Sonraki düğüme işaretçi
        KromozomDugum(Liste* kromozom) : kromozom(kromozom), sonraki(nullptr) {}
    };

    KromozomDugum* ilk; // DNA'daki ilk kromozom düğümüne işaretçi

public:
    DNA(); // DNA yapısını başlatır (ilk düğüm nullptr olarak ayarlanır)
    ~DNA(); // Tüm düğümleri ve içlerindeki veriyi (Liste) silerek belleği temizler
    void kromozomEkle(Liste* kromozom); // Yeni bir kromozomu DNA'ya ekler
    void caprazlama(int indeks1, int indeks2); // İki kromozom arasında çaprazlama yapar
    void mutasyon(int kromozomIndeks, int genIndeks); // Belirtilen kromozomdaki bir gende mutasyon yapar
    void yazdir(); // ekrana yaz işlemi için ilgili kromozomun en küçük genini ekrana yazdırır
    // Otomatik işlemler fonksiyonu
    void otomatikIslemler(const std::string& islemlerDosyasi); // Islemler.txt dosyasını okuyarak işlemleri uygular
    Liste* kromozomGetir(int indeks); // Belirtilen sıradaki kromozomu döndürür
};

#endif
