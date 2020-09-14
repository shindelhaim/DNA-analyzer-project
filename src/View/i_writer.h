#ifndef DNA_TASK_IWRITER_H
#define DNA_TASK_IWRITER_H

class IWriter
{
public:
    virtual ~IWriter(){};
    virtual void write(const char *str) const = 0;
};

#endif //DNA_TASK_IWRITER_H
