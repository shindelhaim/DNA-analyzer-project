#ifndef DNA_TASK_FILEWRITER_H
#define DNA_TASK_FILEWRITER_H

#include <string>
#include "i_writer.h"

class FileWriter: public IWriter
{
public:
    FileWriter(const std::string& nameFile);
    void write(const char *str) const;

private:
    std::string m_nameFile;
};

#endif //DNA_TASK_FILEWRITER_H
