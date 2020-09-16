#ifndef SRC_DNA_META_DATA_H
#define SRC_DNA_META_DATA_H

#include <string>
#include "DNA_sequence.h"


enum Status
{
    UP_TO_DATA,
    MODIFIED,
    NEW
};

class DnaMetaData
{
public:
    DnaMetaData(const DnaSequence& dnaSequence, const std::string &name);
    std::string getDnaDataFormat()const;
    const std::string& getName()const{return m_name;}
    const size_t getId()const{return m_id;}
    const DnaSequence& getDnaSequence()const{return m_dnaSequence;}
    size_t getCountCopies() { return ++m_countCopies;}
    void setStatus(Status status){m_status = status;}
private:
    size_t m_id;
    std::string m_name;
    Status m_status;
    DnaSequence m_dnaSequence;
    size_t m_countCopies;
};


#endif //SRC_DNA_META_DATA_H
