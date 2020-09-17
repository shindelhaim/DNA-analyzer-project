#include "quit_command.h"
#include <stdexcept>
#include <sstream>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../../Model/DNA_meta_data.h"
#include "../../utils.h"

void QuitCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void QuitCommand::execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const
{
    size_t numNewDna = dataBase->getNumNewDna();
    size_t numModifiedDna = dataBase->getModifiedNewDna();
    std::stringstream out;
    bool isNeedAdd = false;
    bool isFinish = true;


    if (numModifiedDna || numNewDna)
    {
        out << "There are ";
        if (numModifiedDna)
        {
            out << numModifiedDna << " modified ";
            isNeedAdd = true;
        }
        if (numNewDna)
        {
            if (isNeedAdd)
            {
                out << "add ";
            }

            out << numNewDna << " new sequences. ";

        }
        out << "Are you sure you want to quit?" << std::endl;
        out << "Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'." << std::endl;
        out << "> confirm >>> ";

        output->write(out.str().c_str());

        std::string confirm;
        input->initInput();
        confirm = input->read();

        while ("y" != confirm && "Y" != confirm && "n" != confirm && "N" != confirm)
        {
            out.str("");
            out << " You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'."
            << std::endl << "> confirm >>> ";
            output->write(out.str().c_str());
            input->initInput();
            confirm = input->read();
        }

        if ("n" == confirm || "N" == confirm)
        {
            isFinish = false;
        }
    }

    if(isFinish)
    {
        out.str("");
        out << "Thank you for using Dnalanyzer." << std::endl << "Goodbye!" << std::endl;
        output->write(out.str().c_str());
        throw std::logic_error("");
    }


}


bool QuitCommand::is_valid()
{
    return 1 == (*m_pParams).getSize();
}

