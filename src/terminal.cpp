#include <iostream>
#include "terminal.h"
#include "parser_params.h"
#include "keyboard_reader.h"
#include "i_command.h"
#include "command_factory.h"
void Terminal::start(DataBaseDnaSequence* dataBase ,IReader* input, IWriter* output)
{

    ParserParams params;
    const ICommand* pCommand = NULL;
    while(1)
    {
        try
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
            pCommand = NULL;
        }
        catch (std::invalid_argument e)
        {
            std::cout << e.what() << std::endl;
            delete pCommand;
            pCommand = NULL;
        }

    }
}