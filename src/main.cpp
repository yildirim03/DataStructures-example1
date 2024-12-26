/**
* @file        b221210049 numaralı öğrenci ödevi
* @description bağlı listeler kullanarak gen,kromozom ve DNA işlemleri yapan program.
* @course      1.öğretim A grubu
* @assignment  ödev-1
* @date        27.11.2024
* @author      BATUHAN YILDIRIM--batuhan.yildirim8@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include "DNA.hpp"
#include <string>

void dnaDosyasiniOku(const std::string& dosyaAdi, DNA& dna) {
    std::ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        std::cerr << "Dosya acilamadi: " << dosyaAdi << std::endl;
        return;
    }

    std::string satir;
    while (std::getline(dosya, satir)) {
        if (satir.empty()) {
            continue; // Boş satırları atla
        }

        Liste* kromozom = new Liste();
        for (char gen : satir) {
            if (std::isalpha(gen)) { // Sadece harfleri kabul et
                kromozom->ekle(gen);
            }
        }

        if (kromozom->dugumGetir(0) != nullptr) { // Kromozom tamamen boş değilse ekle
            dna.kromozomEkle(kromozom);
        } else {
            delete kromozom; // Boşsa, bellek sızıntısını önlemek için sil
        }
    }

    dosya.close();
}


int main() {
    DNA dna;
    dnaDosyasiniOku("Dna.txt", dna);  // DNA dosyasını oku

    int secim;
    do {
        std::cout << "\n1 - Caprazlama\n2 - Mutasyon\n3 - Otomatik Islemler\n4 - Yazdir\n5 - Cikis\nSecim: ";
        std::cin >> secim;

        if (secim == 1) {
            int i1, i2;
            std::cout << "Kromozom 1: "; std::cin >> i1;
            std::cout << "Kromozom 2: "; std::cin >> i2;
            dna.caprazlama(i1, i2);
        } else if (secim == 2) {
            int i1, g1;
            std::cout << "Kromozom: "; std::cin >> i1;
            std::cout << "Gen: "; std::cin >> g1;
            dna.mutasyon(i1, g1);
        } else if (secim == 3) {
            // Otomatik işlemleri başlat
            dna.otomatikIslemler("Islemler.txt");
        } else if (secim == 4) {
            dna.yazdir();
        } else if (secim == 5) {
            std::cout << "Programdan cikiliyor." << std::endl;
        }
        else {
            std::cout << "Geçersiz seçenek, lütfen tekrar deneyin." << std::endl;
        }
    } while (secim != 5); // 5'e basıldığında çıkış yapılır

    return 0;
}
