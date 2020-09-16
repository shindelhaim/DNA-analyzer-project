#ifndef SRC_DB_DNA_SEQUENCE_H
#define SRC_DB_DNA_SEQUENCE_H

#include <map>
#include <cstddef>
#include <string>
#include <vector>

class DnaMetaData;

class DataBaseDnaSequence
{
public:
    void addNewDna(DnaMetaData* dna);
    DnaMetaData* findDnaById(size_t id);
    DnaMetaData* findDnaByName(std::string name);
    bool isNameExist(std::string name);
    const std::vector<size_t> getSortIds() const;

private:
    typedef std::map<size_t,DnaMetaData*> HashById ;
    typedef std::map<std::string,size_t> HashByName ;

    HashById m_hashTableByID;
    HashByName m_hashTableByName;
};



#endif //SRC_DB_DNA_SEQUENCE_H
