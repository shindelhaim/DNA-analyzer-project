#include <sstream>
#include "DNA_meta_data.h"


DnaMetaData::DnaMetaData(const DnaSequence& dnaSequence, const std::string& name )
:m_dnaSequence(dnaSequence),m_status(NEW)
{
    static size_t s_countId = 0;
    m_id = s_countId;
    ++s_countId;

    static size_t s_countDefaultName = 1;
    std::stringstream out;
    if(name == "")
    {
        out <<"seq" << s_countDefaultName;
        m_name = out.str();
        ++s_countDefaultName;
    }
    else
    {
        m_name = name;
    }
}

std::string DnaMetaData::getDnaData() const
{
    std::stringstream out;
    out << "[" << m_id << "] " << m_name <<": ";
    size_t lengthDnaSeq = m_dnaSequence.length();
    if( lengthDnaSeq > 40)
    {
        out << m_dnaSequence.slice(0,32) << "..." <<m_dnaSequence.slice(lengthDnaSeq-3,lengthDnaSeq);
    }
    else
    {
        out << m_dnaSequence;
    }
    return out.str();
}
