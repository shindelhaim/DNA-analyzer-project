#include "system_manager.h"
#include "../View/UI/terminal.h"
#include "commands/command_factory.h"
#include "commands/i_command.h"
#include "callback.h"
void SystemManager::start(UI* userInterface,IReader* input, IWriter* output)
{
    Callback<SystemManager> callback(this, &SystemManager::executeCommand);
    userInterface -> run(&m_dataBaseDnaSequence,callback,input,output);
}

void SystemManager::end()
{
    CommandFactory::release();
}

void SystemManager::executeCommand(ParserParams& params, IReader *input, IWriter *output)
{
    const ICommand* pCommand;
    params.parseInput(*input);
    pCommand = CommandFactory::getCommand(params);
    pCommand -> execute(&m_dataBaseDnaSequence, input, output);
}
