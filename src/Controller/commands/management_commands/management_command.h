#ifndef SRC_MANAGEMENT_COMMANDS_H
#define SRC_MANAGEMENT_COMMANDS_H

#include "../command.h"

class ManagementCommands: public Command
{
public:
    /* virtual */ ~ManagementCommands() = 0;
    /* virtual */ void initParams(const ParserParams& params) = 0;
};


#endif //SRC_MANAGEMENT_COMMANDS_H
