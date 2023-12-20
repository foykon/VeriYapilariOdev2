/**
* @file FileReader.hpp
* @description dosya okuma işlemini yaptığımız ve avl ağaçlarının oluştuğu sınıfın arayüzü
* @course Dersi 1. öğretin a grubu
* @assignment 2. ödev
* @date 8.12.2023
* @author Furkan YILDIZ furkan.yildiz12@ogr.sakarya.edu.tr
*/


#ifndef FileReader_HPP
#define FileReader_HPP

#include "AVLTree.hpp"
#include <string>
#include <fstream>
#include <list>

class FileReader {
public:
    FileReader(const std::string& dosyaAdi);
    bool DosyayiAc();
    void DosyadanOkuVeYazdir();
    void DosyayiKapat();
    std::list<AVLTree *> AVLTreeList;

private:
    int siraNo=1;
    std::string dosyaAdi;
    std::ifstream dosya;
};

#endif // FILE_READER_HPP
