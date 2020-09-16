#include <sstream>
#include "utils.h"
#include "../Model/DNA_meta_data.h"

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