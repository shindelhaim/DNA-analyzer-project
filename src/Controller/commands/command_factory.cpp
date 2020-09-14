#include <stdexcept>
#include "command_factory.h"
#include "creation_commands/new_command.h"
#include "creation_commands/load_command.h"
#include "management_commands/save_command.h"
#include "creation_commands/dup_command.h"

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

    if("save" == nameCommand)
    {
        return new SaveCommand(params);
    }

    if("dup" == nameCommand)
    {
        return new DupCommand(params);
    }

    throw std::invalid_argument("COMMAND NOT FOUND");
}
