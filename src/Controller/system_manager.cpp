#include "system_manager.h"
#include "../View/terminal.h"

void SystemManager::start(UI* userInterface,IReader* input, IWriter* output)
{
    userInterface -> run(&m_dataBaseDnaSequence,input,output);
}
