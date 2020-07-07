#include <stdexcept>
#include <fstream>
#include "FileReader.h"

FileReader::FileReader(const std::string& nameFile)
{
    m_data = readFromFile(nameFile);
}

std::string FileReader::readFromFile(const std::string& nameFile) {
    std::string dnaSeq;
    std::ifstream fileToRead;
    fileToRead.open(nameFile.c_str());
    if(!fileToRead.is_open())
    {
        throw std::runtime_error("it can't to open the file");
    }
    getline(fileToRead,dnaSeq);
    fileToRead.close();
    return dnaSeq;
}
