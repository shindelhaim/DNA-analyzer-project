#ifndef SRC_NEW_COMMAND_H
#define SRC_NEW_COMMAND_H

#include "creation_command.h"
#include "parser_params.h"

class NewCommand: public CreationCommand
{
public:
    NewCommand(const ParserParams& parameters);
    void execute()const;

private:
    bool is_valid();
};

#endif //SRC_NEW_COMMAND_H
