#ifndef SRC_ANALYSIS_COMMAND_H
#define SRC_ANALYSIS_COMMAND_H

#include "../i_command.h"

class AnalysisCommand: public ICommand
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};

#endif //SRC_ANALYSIS_COMMAND_H
