#ifndef SRC_SYSTEM_MANAGER_H
#define SRC_SYSTEM_MANAGER_H


#include "DB_DNA_sequence.h"

class IReader;
class IWriter;

class SystemManager
{
public:
    void start(IReader* input, IWriter* output);

private:
    DataBaseDnaSequence m_dataBaseDnaSequence;
};


#endif //SRC_SYSTEM_MANAGER_H
