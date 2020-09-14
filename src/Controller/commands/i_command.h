#ifndef SRC_I_COMMAND_H
#define SRC_I_COMMAND_H

#include "parser_params.h"
class DataBaseDnaSequence;
class IWriter;

class ICommand
{
public:
    ICommand(const ParserParams& params);
    virtual void execute(DataBaseDnaSequence* dataBase,IWriter* output)const = 0;
    virtual ~ICommand(){};

protected:
    const ParserParams* m_pParams;
    static std::string getValidName(const std::string& name,DataBaseDnaSequence* dataBase);
};

#endif //SRC_I_COMMAND_H
