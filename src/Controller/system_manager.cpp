#include "system_manager.h"
#include "../View/terminal.h"

void SystemManager::start(UI* user_interface,IReader* input, IWriter* output)
{
    user_interface -> run(&m_dataBaseDnaSequence,input,output);
}
