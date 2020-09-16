#include <sstream>
#include "i_command.h"
#include "../../Model/DB_DNA_sequence.h"
#include "../../Model/DNA_meta_data.h"

std::string ICommand::getValidName(const std::string &name,  IReader* input, DataBaseDnaSequence *dataBase)
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
