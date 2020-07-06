#ifndef SRC_DB_DNA_SEQUENCE_H
#define SRC_DB_DNA_SEQUENCE_H

#include <map>
#include <cstddef>
#include <string>

class DnaMetaData;

class DataBaseDnaSequence
{
public:
    static void addNewDna(DnaMetaData* dna);
private:
    static std::map<size_t,DnaMetaData*> m_hashTableByID;
    static std::map<std::string,size_t> m_hashTableByName;
};



#endif //SRC_DB_DNA_SEQUENCE_H
