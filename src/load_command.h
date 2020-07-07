#ifndef SRC_LOAD_COMMAND_H
#define SRC_LOAD_COMMAND_H

#include "creation_command.h"

class LoadCommand: public CreationCommand
{
public:
    LoadCommand(const ParserParams& parameters);
    void execute(DataBaseDnaSequence* dataBase,IWriter* output)const;

private:
    bool is_valid();
};



#endif //SRC_LOAD_COMMAND_H
