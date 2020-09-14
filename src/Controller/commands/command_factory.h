#ifndef SRC_COMMAND_FACTORY_H
#define SRC_COMMAND_FACTORY_H

#include <string>
#include <map>
#include "../parser_params.h"

class ICommand;

class CommandFactory
{
public:
    static void init();
    static void release();
    static ICommand* getCommand(const ParserParams& nameCommand);

private:
    static std::map<std::string,ICommand*> m_commandsHash;
};

#endif //SRC_COMMAND_FACTORY_H
