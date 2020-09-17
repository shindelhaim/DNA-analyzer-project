#ifndef SRC_COMMAND_H
#define SRC_COMMAND_H

#include "../parser_params.h"
#include "i_command.h"
class DataBaseDnaSequence;
class IWriter;

class Command: public ICommand
{
public:
    virtual void initParams(const ParserParams& params) = 0;
    virtual void execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const = 0;
    virtual ~Command(){};

protected:
    const ParserParams* m_pParams;
};

#endif //SRC_COMMAND_H
