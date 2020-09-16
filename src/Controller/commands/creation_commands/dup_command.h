#ifndef SRC_DUP_COMMAND_H
#define SRC_DUP_COMMAND_H

#include "creation_command.h"

class ParserParams;
class IWriter;
class DataBaseDnaSequence;

class DupCommand: public CreationCommand
{
public:
    /* virtual */ void initParams(const ParserParams& parameters);
    void execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output)const;

private:
    bool is_valid();
};


#endif //SRC_DUP_COMMAND_H
