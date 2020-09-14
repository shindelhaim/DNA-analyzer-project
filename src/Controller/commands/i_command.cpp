#include <sstream>
#include "i_command.h"
#include "DB_DNA_sequence.h"
#include "DNA_meta_data.h"

ICommand::ICommand(const ParserParams &params)
{
    m_pParams = &params;
}

std::string ICommand::getValidName(const std::string &name, DataBaseDnaSequence *dataBase)
{
    std::string tempName = name;

    while(dataBase->isNameExist(tempName))
    {
        DnaMetaData* existDna = dataBase->findDnaByName(tempName);
        std::stringstream out;
        out << existDna->getCountCopies();
        tempName = tempName + "_" + out.str();
    }

    return tempName;
}
