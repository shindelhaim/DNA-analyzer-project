#include <stdexcept>
#include <fstream>
#include "FileReader.h"

FileReader::FileReader(const std::string& nameFile):m_nameFile(nameFile)
{

}

void FileReader::initInput()
{
    std::string dnaSeq;
    std::ifstream fileToRead;
    fileToRead.open(m_nameFile.c_str());
    if(!fileToRead.is_open())
    {
        throw std::runtime_error("it can't to open the file");
    }
    getline(fileToRead,dnaSeq);
    fileToRead.close();
    m_data = dnaSeq;
}
