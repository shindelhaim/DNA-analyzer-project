#include <iostream>
#include "terminal.h"
#include "../Controller/parser_params.h"
#include "../View/keyboard_reader.h"
#include "../Controller/commands/i_command.h"
#include "../Controller/commands/command_factory.h"

void Terminal::run(DataBaseDnaSequence* dataBase ,IReader* input, IWriter* output)
{

    ParserParams params;
    const ICommand* pCommand = NULL;
    while(1)
    {
        try
        {
            std::cout << "cmd >>> ";
            input -> initInput();
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
        catch (const std::invalid_argument& e)
        {
            std::cout << "ERROR: "<< e.what() << std::endl;
            delete pCommand;
            pCommand = NULL;
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "ERROR: " << e.what() << std::endl;
            delete pCommand;
            pCommand = NULL;
        }

    }
}