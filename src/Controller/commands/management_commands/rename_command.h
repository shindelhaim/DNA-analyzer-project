#ifndef SRC_RENAME_COMMAND_H
#define SRC_RENAME_COMMAND_H

#include "management_command.h"

class ParserParams;
class IWriter;
class DataBaseDnaSequence;

class RenameCommand: public ManagementCommands
{
public:
    /* virtual */ void initParams(const ParserParams& parameters);
    /* virtual */void execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output)const;

private:
    bool is_valid();
};





#endif //SRC_RENAME_COMMAND_H
