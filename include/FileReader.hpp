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
