#ifndef SRC_CONTROL_COMMAND_H
#define SRC_CONTROL_COMMAND_H

#include "../i_command.h"

class ControlCommand: public ICommand
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};


#endif //SRC_CONTROL_COMMAND_H
