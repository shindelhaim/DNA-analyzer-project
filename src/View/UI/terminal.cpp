#include <iostream>
#include "terminal.h"
#include "../../Controller/parser_params.h"
#include "../reader/keyboard_reader.h"
#include "../../Controller/commands/i_command.h"
#include "../../Controller/commands/command_factory.h"

void Terminal::run(DataBaseDnaSequence* dataBase ,Callback<SystemManager>& callback,IReader* input, IWriter* output)
{

    ParserParams params;
    const ICommand* pCommand = NULL;

    while (true)
    {
        try
        {
            std::cout << "> cmd >>> ";
            input -> initInput();
            callback(params, input, output);

        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "ERROR: "<< e.what() << std::endl;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "ERROR: "<< e.what() << std::endl;
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "ERROR: " << e.what() << std::endl;
        }
        catch (const std::logic_error& e)
        {
            break;
        }

    }
}