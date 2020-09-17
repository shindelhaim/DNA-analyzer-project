#ifndef SRC_CREATION_COMMAND_H
#define SRC_CREATION_COMMAND_H
#include "../command.h"

class CreationCommand: public Command
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};

#endif //SRC_CREATION_COMMAND_H
