#include "system_manager.h"
#include "terminal.h"

void SystemManager::start(const IReader& input, const IWriter& output)
{
    Terminal::start(input,output);
}
