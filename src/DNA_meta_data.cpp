#include <sstream>
#include "DNA_meta_data.h"


DnaMetaData::DnaMetaData(const DnaSequence& dnaSequence, const std::string& name )
:m_dnaSequence(dnaSequence),m_status(NEW),m_countCopies(1)
{
    static size_t s_countId = 0;

    m_id = s_countId;
    ++s_countId;

}

std::string DnaMetaData::getDnaData() const
{
    std::stringstream out;
    out << "[" << m_id << "] " << m_name <<": "<< m_dnaSequence;
    return out.str();
}
