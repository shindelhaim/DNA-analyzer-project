#ifndef SRC_LIST_COMMAND_H
#define SRC_LIST_COMMAND_H

#include "control_command.h"

class ParserParams;
class IWriter;
class DataBaseDnaSequence;

class ListCommand: public ControlCommand
{
public:
    /* virtual */ void initParams(const ParserParams& parameters);
    void execute(DataBaseDnaSequence* dataBase,IWriter* output)const;

private:
    bool is_valid();
};

#endif //SRC_LIST_COMMAND_H
