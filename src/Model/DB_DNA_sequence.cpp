#include <stdexcept>
#include <algorithm>
#include "DB_DNA_sequence.h"
#include "DNA_meta_data.h"

DataBaseDnaSequence::DataBaseDnaSequence()
{
    std::vector<size_t> emptyVec;
    m_hashtableByStatus.insert(std::pair<Status,std::vector<size_t> >(NEW, emptyVec));
    m_hashtableByStatus.insert(std::pair<Status,std::vector<size_t> >(MODIFIED, emptyVec));
    m_hashtableByStatus.insert(std::pair<Status,std::vector<size_t> >(UP_TO_DATA, emptyVec));
}


void DataBaseDnaSequence::addNewDna(DnaMetaData *dna)
{
    m_hashTableByID.insert(std::pair<size_t,DnaMetaData*>(dna->getId(),dna));
    m_hashTableByName.insert(std::pair<std::string,size_t>(dna->getName(),dna->getId()));
    m_hashtableByStatus.at(dna->getStatus()).push_back(dna->getId());
}

DnaMetaData* DataBaseDnaSequence::findDnaById(size_t id)
{
    HashById::iterator iterFound = m_hashTableByID.find(id);
    if(iterFound == m_hashTableByID.end())
    {
        throw std::invalid_argument("ID NOT FOUND IN DATABASE");
    }
    return iterFound->second;
}

DnaMetaData* DataBaseDnaSequence::findDnaByName(std::string name)
{
    HashByName ::iterator iterFound = m_hashTableByName.find(name);
    if(iterFound == m_hashTableByName.end())
    {
        throw std::invalid_argument("NAME NOT FOUND IN DATABASE");
    }
    size_t id = iterFound->second;
    return findDnaById(id);
}

bool DataBaseDnaSequence::isNameExist(std::string name)
{
    try {
        findDnaByName(name);
    }
    catch (const std::invalid_argument& e)
    {
        return false;
    }
    return true;
}

const std::vector<size_t> DataBaseDnaSequence::getSortIds() const
{
    std::vector<size_t> ids;
    HashById::const_iterator iterId;

    for (iterId = m_hashTableByID.begin(); iterId != m_hashTableByID.end(); ++iterId)
    {
        ids.push_back(iterId -> first);
    }

    std::sort(ids.begin(),ids.end());

    return ids;
}

size_t DataBaseDnaSequence::getNumNewDna() const
{
    return m_hashtableByStatus.at(NEW).size();
}

size_t DataBaseDnaSequence::getModifiedNewDna() const
{
    return m_hashtableByStatus.at(MODIFIED).size();
}

void DataBaseDnaSequence::moveStatus(DnaMetaData* pDnaMetaData, Status dest)
{

    std::vector<size_t>::iterator iterFind;
    std::vector<size_t>& vecOldStatus = m_hashtableByStatus.at(pDnaMetaData->getStatus());
    iterFind = std::find(vecOldStatus.begin(), vecOldStatus.end(), pDnaMetaData->getId());
    vecOldStatus.erase(iterFind);

    m_hashtableByStatus.at(dest).push_back(pDnaMetaData->getId());

    pDnaMetaData -> setStatus(dest);

}


