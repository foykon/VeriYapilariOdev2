/**
* @file main.cpp
* @description programın ana classı main
* @course Dersi 1. öğretin a grubu
* @assignment 2. ödev
* @date 8.12.2023
* @author Furkan YILDIZ furkan.yildiz12@ogr.sakarya.edu.tr
*/
#include "FileReader.hpp"
#include <iostream>

int main() {
    // Dosya adını belirleyin
    std::string filename = "Veri.txt";

    // FileReader sınıfını kullanarak dosyadan veri okuma
    FileReader fileReader(filename);

    // Tüm satırları oku ve ekrana yazdır
    std::vector<std::string> lines = fileReader.ReadAllLines();
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }

    return 0;
}