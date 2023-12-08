#include "FileReader.hpp"
#include "AVLTree.hpp"
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>


FileReader::FileReader(const std::string& dosyaAdi) : dosyaAdi(dosyaAdi) {}

bool FileReader::DosyayiAc() {
    dosya.open(dosyaAdi);
    return dosya.is_open();
}

void FileReader::DosyadanOkuVeYazdir() {
    // std::string satir;
    // while (std::getline(dosya, satir)) {
    //     std::cout << satir << std::endl;
    // }
    
    
    if (!dosya.is_open()) {
        std::cerr << "Dosya acilamadi!" << std::endl;
        return ;
    }

    std::string satir;

    // Dosyadan satır okuma
    while (std::getline(dosya, satir)) {
        std::istringstream iss(satir);
        int sayi;
        //yeni avl ağacı üretimi
        AVLTree* avlTree = new AVLTree();
        // Satırdaki her bir sayıyı ayır ve işle
        while (iss >> sayi) {
            // avl ağacına ekleme
            avlTree->insert(sayi);
        }
        //Avlye ekleme
        AVLTreeList.push_back(avlTree);
        avlTree->display();

        // Satırın sonunda uyarı ver
        std::cout << "\nSatir bitti!\n";
    }
    //avlliste elemanlarını dönmek için
    for (const auto& element : AVLTreeList) {
        element->display();
    }
    std::cout << std::endl;

    dosya.close();
}

void FileReader::DosyayiKapat() {
    dosya.close();
}
