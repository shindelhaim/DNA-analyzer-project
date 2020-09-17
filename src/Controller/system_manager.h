#ifndef SRC_SYSTEM_MANAGER_H
#define SRC_SYSTEM_MANAGER_H


#include "../Model/DB_DNA_sequence.h"

class IReader;
class IWriter;
class UI;

class SystemManager
{
public:
    void start(UI* user_interface, IReader* input, IWriter* output);
    void end();

private:
    DataBaseDnaSequence m_dataBaseDnaSequence;
};


#endif //SRC_SYSTEM_MANAGER_H
