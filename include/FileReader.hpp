#ifndef FileReader_HPP
#define FileReader_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class FileReader {
public:
    FileReader(const std::string& filename);
    ~FileReader();
    std::string ReadLine();
    std::vector<std::string> ReadAllLines();

private:
    std::string filename_;
    std::ifstream file_;
};

#endif // FILEREADER_HPP

