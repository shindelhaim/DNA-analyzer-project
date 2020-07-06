#include <fstream>
#include "file_writer.h"

FileWriter::FileWriter(const std::string& nameFile):m_nameFile(nameFile)
{

}


void FileWriter::write(const char *str) const
{
    std::string dnaSeq;
    std::ofstream fileTowrite;
    fileTowrite.open(m_nameFile.c_str());
    if(!fileTowrite.is_open())
    {
        throw std::runtime_error("Can't to open the file");
    }
    fileTowrite<<str;
    fileTowrite.close();
}

