#include <iostream>
#include "terminal.h"
#include "parser_params.h"
#include "keyboard_reader.h"
#include "i_command.h"
#include "command_factory.h"
void Terminal::start(DataBaseDnaSequence* dataBase ,IReader* input, IWriter* output)
{

    ParserParams params;
    const ICommand* pCommand;
    while(1)
    {

        std::cout << "cmd >>> ";
        input->initInput();
        params.parseInput(*input);
        if("quit" == params[0])
        {
            break;
        }
        pCommand = CommandFactory::getCommand(params);
        pCommand -> execute(dataBase,output);

        delete pCommand;
    }
}