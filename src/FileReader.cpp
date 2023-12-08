#include "FileReader.hpp"

FileReader::FileReader(const std::string& filename) : filename_(filename) {
    file_.open(filename_);
}

FileReader::~FileReader() {
    if (file_.is_open()) {
        file_.close();
    }
}

std::string FileReader::ReadLine() {
    std::string line;
    if (file_.is_open()) {
        std::getline(file_, line);
    }
    return line;
}

std::vector<std::string> FileReader::ReadAllLines() {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file_, line)) {
        lines.push_back(line);
    }
    return lines;
}
