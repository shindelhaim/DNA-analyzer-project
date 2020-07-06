#ifndef DNA_TASK_SCREENWRITER_H
#define DNA_TASK_SCREENWRITER_H

#include <string>
#include "i_writer.h"

class ScreenWriter: public IWriter
{
public:
    void write(const char *str) const;
};


#endif //DNA_TASK_SCREENWRITER_H
