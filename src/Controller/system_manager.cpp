#include "system_manager.h"
#include "../View/UI/terminal.h"
#include "commands/command_factory.h"

void SystemManager::start(UI* userInterface,IReader* input, IWriter* output)
{
    userInterface -> run(&m_dataBaseDnaSequence,input,output);
}

void SystemManager::end()
{
    CommandFactory::release();
}
