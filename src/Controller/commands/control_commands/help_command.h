#ifndef SRC_HELP_COMMAND_H
#define SRC_HELP_COMMAND_H

#include "control_command.h"

class ParserParams;
class IWriter;
class DataBaseDnaSequence;

class HelpCommand: public ControlCommand
{
public:
    /* virtual */ void initParams(const ParserParams& parameters);
    void execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output)const;

private:
    bool is_valid();
    const std::string getAvailableCommands() const;
    const std::string getInfoCommand(const std::string& commandName) const;
};


#endif //SRC_HELP_COMMAND_H
