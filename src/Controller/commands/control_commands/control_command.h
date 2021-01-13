#ifndef SRC_CONTROL_COMMAND_H
#define SRC_CONTROL_COMMAND_H

#include "../command.h"

class ControlCommand: public Command
{
public:
    /* virtual */ ~ControlCommands() = 0;
    /* virtual */ void initParams(const ParserParams& params) = 0;
};


#endif //SRC_CONTROL_COMMAND_H
