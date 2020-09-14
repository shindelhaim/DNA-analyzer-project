#ifndef SRC_TERMINAL_H
#define SRC_TERMINAL_H

#include "user_interface.h"

class IReader;
class IWriter;
class DataBaseDnaSequence;

class Terminal : public UI
{
public:
    void run(DataBaseDnaSequence* dataBaseDnaSequence, IReader* input, IWriter* output);
};





#endif //SRC_TERMINAL_H
