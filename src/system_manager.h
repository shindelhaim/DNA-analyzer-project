#ifndef SRC_SYSTEM_MANAGER_H
#define SRC_SYSTEM_MANAGER_H


#include "DB_DNA_sequence.h"

class IReader;
class IWriter;

class SystemManager
{
public:
    static void start(const IReader& input, const IWriter& output);

private:
    DataBaseDnaSequence dataBaseDnaSequence;
};


#endif //SRC_SYSTEM_MANAGER_H
