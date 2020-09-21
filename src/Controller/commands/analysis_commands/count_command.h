#ifndef SRC_COUNT_COMMAND_H
#define SRC_COUNT_COMMAND_H

#include "analysis_command.h"

class ParserParams;
class DataBaseDnaSequence;


class CountCommand: public AnalysisCommand
{
public:
    /* virtual */ void initParams(const ParserParams& parameters);
    void execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const;

private:
    bool is_valid();
};



#endif //SRC_COUNT_COMMAND_H
