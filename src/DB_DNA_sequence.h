#ifndef SRC_DB_DNA_SEQUENCE_H
#define SRC_DB_DNA_SEQUENCE_H

#include <map>
#include <cstddef>
#include <string>

class DnaMetaData;

class DataBaseDnaSequence
{
public:
    void addNewDna(DnaMetaData* dna);
private:
    std::map<size_t,DnaMetaData*> m_hashTableByID;
    std::map<std::string,size_t> m_hashTableByName;
};



#endif //SRC_DB_DNA_SEQUENCE_H
