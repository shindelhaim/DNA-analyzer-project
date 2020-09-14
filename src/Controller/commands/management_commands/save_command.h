#ifndef SRC_SAVE_COMMAND_H
#define SRC_SAVE_COMMAND_H

#include "management_command.h"

class ParserParams;
class IWriter;
class DataBaseDnaSequence;

class SaveCommand: public ManagementCommands
{
public:
    SaveCommand(const ParserParams& parameters);
    /* virtual */void execute(DataBaseDnaSequence* dataBase,IWriter* output)const;

private:
    bool is_valid();
};


#endif /*SRC_SAVE_COMMAND_H*/
