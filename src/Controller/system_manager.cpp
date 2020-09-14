#include "system_manager.h"
#include "terminal.h"

void SystemManager::start(IReader* input, IWriter* output)
{
    Terminal::start(&m_dataBaseDnaSequence,input,output);
}
