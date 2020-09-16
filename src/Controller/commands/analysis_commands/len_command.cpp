#include "len_command.h"
#include <stdexcept>
#include <sstream>
#include <string>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../../Model/DNA_meta_data.h"
#include "../../utils.h"

void LenCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void LenCommand::execute(DataBaseDnaSequence* dataBase,IWriter* output) const
{
    DnaMetaData* dnaMetaData;
    size_t lenDna;
    DnaMetaData* pDna;
    if((*m_pParams)[1][0] == '@')
    {
        pDna = dataBase->findDnaByName((*m_pParams)[1].substr(1));
    }
    else
    {
        std::istringstream in((*m_pParams)[1].substr(1));
        size_t id;
        in >> id;
        pDna = dataBase->findDnaById(id);
    }

    lenDna = pDna->getDnaSequence().length();
    std::stringstream out;
    out << lenDna;
    output->write(out.str().c_str());

}



bool LenCommand::is_valid()
{
    return 2 == (*m_pParams).getSize()
           && ((*m_pParams)[1][0] == '@' || ((*m_pParams)[1][0] == '#' && Utils::isNumber(((*m_pParams)[1]).substr(1))));
}
