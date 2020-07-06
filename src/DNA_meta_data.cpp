#include "DNA_meta_data.h"

const std::string &DnaMetaData::getName() const{
    return m_name;
}

DnaMetaData::DnaMetaData(const DnaSequence& dnaSequence, const std::string& name )
:m_dnaSequence(dnaSequence),m_status(NEW)
{
    static size_t s_countDefaultName = 1;
    if(name.empty())
    {
        m_name = "seq" + s_countDefaultName;
    }
    else
    {
        m_name = name;
    }
}
