#include "help_command.h"
#include <stdexcept>
#include <sstream>
#include <fstream>
#include "../../../Model/DB_DNA_sequence.h"
#include "../command_factory.h"

void HelpCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void HelpCommand::execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const
{
    if (1 == m_pParams -> getSize())
    {
        output->write(getAvailableCommands().c_str());
        return;
    }

    output->write(getInfoCommand((*m_pParams)[1]).c_str());

}



bool HelpCommand::is_valid()
{
    return 1 == m_pParams -> getSize() || 2 == m_pParams -> getSize();
}

const std::string HelpCommand::getAvailableCommands() const
{
    std::stringstream out;
    out << "The list of all available commands:" << std::endl;
    std::vector<std::string> commandNames = CommandFactory::getCommandNames();
    std::vector<std::string>::iterator iterName;

    for(iterName = commandNames.begin(); iterName != commandNames.end(); ++iterName)
    {
        out << *iterName << std::endl;
    }

    return out.str();
}

const std::string HelpCommand::getInfoCommand(const std::string& commandName) const
{
    std::stringstream out;
    std::string line;
    std::ifstream fileToRead;

    fileToRead.open(("../Model/info_commands/info_" + commandName + "_command.txt").c_str());
    if(!fileToRead.is_open())
    {
        throw std::runtime_error("COMMAND NAME NOT FOUND");
    }

    while(getline(fileToRead,line))
    {
        out << line << std::endl;
    }

    fileToRead.close();

    return out.str();

}


