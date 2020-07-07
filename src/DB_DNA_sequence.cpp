#include "DB_DNA_sequence.h"
#include "DNA_meta_data.h"

void DataBaseDnaSequence::addNewDna(DnaMetaData *dna)
{
    m_hashTableByID.insert(std::pair<size_t,DnaMetaData*>(dna->getId(),dna));
    m_hashTableByName.insert(std::pair<std::string,size_t>(dna->getName(),dna->getId()));

}

