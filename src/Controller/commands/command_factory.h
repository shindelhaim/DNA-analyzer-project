#ifndef SRC_COMMAND_FACTORY_H
#define SRC_COMMAND_FACTORY_H

#include <string>
#include "i_command.h"
#include "parser_params.h"

class CommandFactory
{
public:
    static ICommand* getCommand(const ParserParams& nameCommand);
};

#endif //SRC_COMMAND_FACTORY_H
