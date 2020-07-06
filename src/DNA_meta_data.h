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
    DnaMetaData(const DnaSequence& dnaSequence, const std::string &name = std::string());
    const std::string& getName()const;
private:
    std::string m_name;
    Status m_status;
    DnaSequence m_dnaSequence;
};


#endif //SRC_DNA_META_DATA_H
