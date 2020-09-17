#ifndef SRC_ANALYSIS_COMMAND_H
#define SRC_ANALYSIS_COMMAND_H

#include "../command.h"

class AnalysisCommand: public Command
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};

#endif //SRC_ANALYSIS_COMMAND_H
