#ifndef SRC_DB_DNA_SEQUENCE_H
#define SRC_DB_DNA_SEQUENCE_H

#include <map>
#include <cstddef>
#include <string>
#include <vector>
#include "DNA_meta_data.h"


class DataBaseDnaSequence
{
public:
    DataBaseDnaSequence();
    void addNewDna(DnaMetaData* dna);
    DnaMetaData* findDnaById(size_t id);
    DnaMetaData* findDnaByName(std::string name);
    bool isNameExist(std::string name);
    const std::vector<size_t> getSortIds() const;
    size_t getNumNewDna() const ;
    size_t getModifiedNewDna() const ;
    void moveStatus(DnaMetaData* pDnaMetaData, Status dest);

private:
    typedef std::map<size_t,DnaMetaData*> HashById ;
    typedef std::map<std::string,size_t> HashByName ;
    typedef std::map< Status,std::vector<size_t> > HashByStatus;

    HashById m_hashTableByID;
    HashByName m_hashTableByName;
    HashByStatus m_hashtableByStatus;
};



#endif //SRC_DB_DNA_SEQUENCE_H
