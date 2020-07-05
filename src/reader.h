#ifndef DNA_TASK_READER_H
#define DNA_TASK_READER_H

#include "i_reader.h"

class reader: public i_reader
{
public:
    std::string read() const;

protected:
    std:: string m_data;
};

#endif //DNA_TASK_READER_H
