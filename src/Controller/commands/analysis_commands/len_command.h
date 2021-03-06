#ifndef SRC_LEN_COMMAND_H
#define SRC_LEN_COMMAND_H

#include "analysis_command.h"

class ParserParams;
class IWriter;
class DataBaseDnaSequence;


class LenCommand: public AnalysisCommand
{
public:
    /* virtual */ void initParams(const ParserParams& parameters);
    void execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output)const;

private:
    bool is_valid();
};


#endif //SRC_LEN_COMMAND_H
