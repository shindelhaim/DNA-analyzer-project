#ifndef DNA_TASK_IREADER_H
#define DNA_TASK_IREADER_H

#include <string>

class IReader
{
public:
    virtual std::string read() const = 0;
    virtual void initInput() = 0;
    virtual ~IReader(){};
};

#endif //DNA_TASK_IREADER_H
