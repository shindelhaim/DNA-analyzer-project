#include "DB_DNA_sequence.h"
#include "DNA_meta_data.h"

std::map<size_t,DnaMetaData*> DataBaseDnaSequence::m_hashTableByID = std::map<size_t,DnaMetaData*>();
std::map<std::string,size_t> DataBaseDnaSequence::m_hashTableByName = std::map<std::string,size_t>();

void DataBaseDnaSequence::addNewDna(DnaMetaData *dna)
{
    m_hashTableByID.insert(std::pair<size_t,DnaMetaData*>(dna->getId(),dna));
    m_hashTableByName.insert(std::pair<std::string,size_t>(dna->getName(),dna->getId()));

}

