#ifndef FileReader_HPP
#define FileReader_HPP

#include "AVLTree.hpp"
#include <string>
#include <fstream>
#include <vector>

class FileReader {
public:
    FileReader(const std::string& dosyaAdi);
    bool DosyayiAc();
    void DosyadanOkuVeYazdir();
    void DosyayiKapat();

private:
    std::vector<AVLTree *> AVLTreeList;
    std::string dosyaAdi;
    std::ifstream dosya;
};

#endif // FILE_READER_HPP
