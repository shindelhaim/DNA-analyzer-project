#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H

#include "parser_params.h"

class ICommand
{
public:
    ICommand(const ParserParams& params);
    virtual void execute()const = 0;
    virtual ~ICommand(){};

protected:
    const ParserParams* m_pParams;
};

#endif //SRC_I_COMMAND_H
