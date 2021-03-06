#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H

#include "../parser_params.h"
class DataBaseDnaSequence;
class IWriter;

class ICommand
{
public:

    virtual void initParams(const ParserParams& params) = 0;
    virtual void execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const = 0;
    virtual ~ICommand(){};
};

#endif //SRC_I_COMMAND_H
