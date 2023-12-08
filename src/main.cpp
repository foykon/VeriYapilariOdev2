/**
* @file main.cpp
* @description programın ana classı main
* @course Dersi 1. öğretin a grubu
* @assignment 2. ödev
* @date 8.12.2023
* @author Furkan YILDIZ furkan.yildiz12@ogr.sakarya.edu.tr
*/
#include "FileReader.hpp"
#include "AVLTree.hpp"
#include <iostream>
#include <list>
using namespace std;
int main() {


    // Dosya adını ve yolunu belirtin
    std::string dosyaAdi = "Veri.txt";
    
    // FileReader sınıfından bir nesne oluşturun
    FileReader fileReader(dosyaAdi);

    // Dosyayı aç
    if (!fileReader.DosyayiAc()) {
        std::cerr << "Dosya acilamadi: " << dosyaAdi << std::endl;
        return 1;
    }

    // Dosyadan oku ve ekrana yazdır
    fileReader.DosyadanOkuVeYazdir();

    //işlem yapabilmek için listeyi main kısmına çektik
    list<AVLTree *> AVLTreeList = fileReader.AVLTreeList;

    // Dosyayı kapat
    fileReader.DosyayiKapat();

    cout<<"--------";
    for (const auto& element : AVLTreeList) {
        

        
    }

    return 0;
}
