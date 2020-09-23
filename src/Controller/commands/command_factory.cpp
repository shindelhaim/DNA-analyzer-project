#include <stdexcept>
#include "command_factory.h"
#include "i_command.h"
#include "creation_commands/new_command.h"
#include "creation_commands/load_command.h"
#include "creation_commands/dup_command.h"
#include "management_commands/save_command.h"
#include "analysis_commands/len_command.h"
#include "analysis_commands/find_command.h"
#include "analysis_commands/count_command.h"
#include "analysis_commands/find_all_command.h"
#include "control_commands/list_command.h"
#include "control_commands/show_command.h"
#include "control_commands/quit_command.h"
#include "control_commands/help_command.h"

std::map<std::string,ICommand*> CommandFactory::m_commandsHash;


struct InitCommandHash
{
    InitCommandHash()
    {
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("new", (new NewCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("load",( new LoadCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("dup", (new DupCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("save", (new SaveCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("len", (new LenCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("find", (new FindCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("list", (new ListCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("show", (new ShowCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("quit", (new QuitCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("help", (new HelpCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("count", (new CountCommand)));
        CommandFactory::m_commandsHash.insert(CommandFactory::PairCommand("findall", (new FindAllCommand)));

    }
}InitCommandHash;


ICommand* CommandFactory::getCommand(const ParserParams& params)
{
    std::string nameCommand = params[0];
    ICommand* command;

    if (params.getSize() == 1 && nameCommand.empty())
    {
        throw std::invalid_argument("MISSING COMMAND");
    }

    try
    {
        command = m_commandsHash.at(nameCommand);
        command -> initParams(params);
        return command;
    }
    catch(std::out_of_range &e)
    {
        throw std::invalid_argument("COMMAND NOT FOUND");
    }

}


void CommandFactory::release()
{
    delete m_commandsHash.at("new");
    delete m_commandsHash.at("load");
    delete m_commandsHash.at("dup");
    delete m_commandsHash.at("save");
    delete m_commandsHash.at("len");
    delete m_commandsHash.at("find");
    delete m_commandsHash.at("list");
    delete m_commandsHash.at("show");
    delete m_commandsHash.at("quit");
    delete m_commandsHash.at("help");
    delete m_commandsHash.at("count");
    delete m_commandsHash.at("findall");



}


std::vector<std::string> CommandFactory::getCommandNames()
{
    HashCommands::iterator iterCommand;
    std::vector<std::string> commandNames;

    for(iterCommand = m_commandsHash.begin(); iterCommand != m_commandsHash.end(); ++iterCommand)
    {
        commandNames.push_back(iterCommand -> first);
    }

    return commandNames;
}
