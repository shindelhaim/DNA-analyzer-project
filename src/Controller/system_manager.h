#ifndef SRC_SYSTEM_MANAGER_H
#define SRC_SYSTEM_MANAGER_H


#include "../Model/DB_DNA_sequence.h"

class IReader;
class IWriter;
class UI;

#include "parser_params.h"

class SystemManager
{
public:
    void start(UI* user_interface, IReader* input, IWriter* output);
    void end();
    void executeCommand(ParserParams& params, IReader* input, IWriter* output);

private:
    DataBaseDnaSequence m_dataBaseDnaSequence;
};


#endif //SRC_SYSTEM_MANAGER_H
