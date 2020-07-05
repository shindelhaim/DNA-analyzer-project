#ifndef DNA_TASK_IREADER_H
#define DNA_TASK_IREADER_H

#include <string>

class i_reader
{
public:
    virtual std::string read() const = 0;
    virtual ~i_reader(){};
};

#endif //DNA_TASK_IREADER_H
