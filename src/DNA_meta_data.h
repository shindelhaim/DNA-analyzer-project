#ifndef SRC_DNA_META_DATA_H
#define SRC_DNA_META_DATA_H

#include <string>
#include "Dna_sequence.h"


enum Status
{
    UP_TO_DATA,
    MODIFIED,
    NEW
};

class DnaMetaData
{
public:
    DnaMetaData(const DnaSequence& dnaSequence, const std::string &name = "");
    std::string getDnaData()const;
    const std::string& getName()const{return m_name;}
    const size_t getId()const{return m_id;}
private:
    size_t m_id;
    std::string m_name;
    Status m_status;
    DnaSequence m_dnaSequence;
};


#endif //SRC_DNA_META_DATA_H
