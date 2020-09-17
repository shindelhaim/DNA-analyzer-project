#ifndef SRC_COMMAND_FACTORY_H
#define SRC_COMMAND_FACTORY_H

#include <string>
#include <map>
#include "../parser_params.h"

class ICommand;

class CommandFactory
{
public:
    static void release();
    static ICommand* getCommand(const ParserParams& nameCommand);
    static std::vector<std::string> getCommandNames();

private:
    friend struct InitCommandHash;
    typedef std::map<std::string,ICommand*> HashCommands;
    static HashCommands m_commandsHash;
};

#endif //SRC_COMMAND_FACTORY_H
