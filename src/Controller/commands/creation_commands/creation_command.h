#ifndef SRC_CREATION_COMMAND_H
#define SRC_CREATION_COMMAND_H
#include "../i_command.h"

class CreationCommand: public ICommand
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};

#endif //SRC_CREATION_COMMAND_H
