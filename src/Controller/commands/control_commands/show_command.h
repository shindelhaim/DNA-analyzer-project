#ifndef SRC_SHOW_COMMAND_H
#define SRC_SHOW_COMMAND_H

#include "control_command.h"

class ParserParams;
class IWriter;
class DataBaseDnaSequence;
class DnaMetaData;

class ShowCommand: public ControlCommand
{
public:
    /* virtual */ void initParams(const ParserParams& parameters);
    void execute(DataBaseDnaSequence* dataBase,IWriter* output)const;

private:
    std::string getSpecifiesFormat(const DnaMetaData* dnaMetaData) const ;
    bool is_valid();
};


#endif //SRC_SHOW_COMMAND_H
