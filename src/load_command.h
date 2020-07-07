#ifndef SRC_LOAD_COMMAND_H
#define SRC_LOAD_COMMAND_H

#include "creation_command.h"

class LoadCommand: public CreationCommand
{
public:
    LoadCommand(const ParserParams& parameters);
    void execute()const;

private:
    bool is_valid();
};



#endif //SRC_LOAD_COMMAND_H
