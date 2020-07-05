#include <stdexcept>
#include "command_factory.h"
#include "new_command.h"

ICommand *CommandFactory::getCommand(const ParserParams& params)
{
    if(params[0] == "new")
    {
        return new NewCommand(params);
    }

    throw std::invalid_argument("COMMAND NOT FOUND");
}
