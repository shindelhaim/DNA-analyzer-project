#ifndef SRC_LOAD_COMMAND_H
#define SRC_LOAD_COMMAND_H

#include "creation_command.h"
class DnaMetaData;

class LoadCommand: public CreationCommand
{
public:
    LoadCommand(const ParserParams& parameters);
    void execute(DataBaseDnaSequence* dataBase,IWriter* output)const;

private:
    bool is_valid();
    static std::string getDnaMetaDataAsStr(const DnaMetaData* dnaMetaData);
};



#endif //SRC_LOAD_COMMAND_H
