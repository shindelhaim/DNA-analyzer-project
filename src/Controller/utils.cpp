#include <sstream>
#include "utils.h"
#include "../Model/DNA_meta_data.h"
#include "../Model/DB_DNA_sequence.h"


std::string Utils::getShortDnaMetaDataFormat(const DnaMetaData* dnaMetaData)
{
    std::stringstream out;
    out << "[" << dnaMetaData->getId() << "] " << dnaMetaData->getName() <<": ";
    size_t lengthDnaSeq = (dnaMetaData->getDnaSequence()).length();
    if( lengthDnaSeq > 40)
    {
        out << (dnaMetaData->getDnaSequence()).slice(0,32) << "..." <<(dnaMetaData->getDnaSequence()).slice(lengthDnaSeq-3,lengthDnaSeq);
    }
    else
    {
        out << (dnaMetaData->getDnaSequence());
    }
    return out.str();
}

bool Utils::isNumber(const std::string& str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

std::string Utils::getValidName(const std::string &name, DataBaseDnaSequence *dataBase)
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