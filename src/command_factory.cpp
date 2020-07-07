#include <stdexcept>
#include "command_factory.h"
#include "new_command.h"
#include "load_command.h"

ICommand *CommandFactory::getCommand(const ParserParams& params)
{
    std::string nameCommand = params[0];
    if("new" == nameCommand)
    {
        return new NewCommand(params);
    }
    if("load" == nameCommand)
    {
        return new LoadCommand(params);
    }

    throw std::invalid_argument("COMMAND NOT FOUND");
}
