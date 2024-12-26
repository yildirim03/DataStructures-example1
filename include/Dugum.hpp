/**
* @file        b221210049 numaralı öğrenci ödevi
* @description bağlı listeler kullanarak gen,kromozom ve DNA işlemleri yapan program.
* @course      1.öğretim A grubu
* @assignment  ödev-1
* @date        27.11.2024
* @author      BATUHAN YILDIRIM--batuhan.yildirim8@ogr.sakarya.edu.tr
*/

#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum {
public:
    char veri;      // Genetik bilgi (karakter)
    Dugum* sonraki; // Sonraki düğüme işaretçi
    Dugum* onceki;  // Önceki düğüme işaretçi

    Dugum(char veri); // Yapıcı: Düğümün verisini alır ve sonraki ve önceki düğümleri nullptr olarak başlatır
};

#endif
