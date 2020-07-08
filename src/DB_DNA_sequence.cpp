#include "DB_DNA_sequence.h"
#include "DNA_meta_data.h"

void DataBaseDnaSequence::addNewDna(DnaMetaData *dna)
{
    m_hashTableByID.insert(std::pair<size_t,DnaMetaData*>(dna->getId(),dna));
    m_hashTableByName.insert(std::pair<std::string,size_t>(dna->getName(),dna->getId()));

}

DnaMetaData &DataBaseDnaSequence::findDnaById(size_t id)
{
    return *(m_hashTableByID.find(id)->second);
}

DnaMetaData &DataBaseDnaSequence::findDnaByName(std::string name)
{
    size_t id = m_hashTableByName.find(name)->second;
    return findDnaById(id);
}

