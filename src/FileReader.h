#ifndef DNA_TASK_FILEREADER_H
#define DNA_TASK_FILEREADER_H

#include <string>
#include "Reader.h"

class FileReader : public Reader
{
public:
    FileReader(const std::string& nameFile);

private:
    static std::string readFromFile(const std::string& nameFile);
};


#endif //DNA_TASK_FILEREADER_H
