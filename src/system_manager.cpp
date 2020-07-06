#include <iostream>
#include "DB_DNA_sequence.h"
#include "system_manager.h"
#include "parser_params.h"
#include "keyboard_reader.h"
#include "i_command.h"
#include "command_factory.h"

void system_manager::start()
{
    DataBaseDnaSequence dataBaseDnaSequence;
    keyboard_reader userInput;
    ParserParams params;
    const ICommand* pCommand;
    while(1)
    {

        std::cout << "cmd >>> ";
        userInput.initInput();
        params.parseInput(userInput);
        if("quit" == params[0])
        {
            break;
        }
        pCommand = CommandFactory::getCommand(params);
        pCommand -> execute();

        delete pCommand;
    }
}
