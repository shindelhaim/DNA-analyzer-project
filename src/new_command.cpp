#include <stdexcept>
#include "new_command.h"

void NewCommand::execute() const
{

}

NewCommand::NewCommand(const ParserParams &parameters) :CreationCommand(parameters)
{
    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }
}

bool NewCommand::is_valid() {
    return true;
}
