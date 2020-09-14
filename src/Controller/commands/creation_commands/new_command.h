#ifndef SRC_NEW_COMMAND_H
#define SRC_NEW_COMMAND_H

#include "creation_command.h"

class ParserParams;
class IWriter;
class DataBaseDnaSequence;

class NewCommand: public CreationCommand
{
public:
    /* virtual */ void initParams(const ParserParams& parameters);
    void execute(DataBaseDnaSequence* dataBase,IWriter* output)const;

private:
    bool is_valid();
};

#endif //SRC_NEW_COMMAND_H
