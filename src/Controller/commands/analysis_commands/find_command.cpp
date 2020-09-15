#include "find_command.h"
#include <stdexcept>
#include <sstream>
#include <string>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../parser_params.h"
#include "../../../Model/DNA_meta_data.h"

void FindCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void FindCommand::execute(DataBaseDnaSequence* dataBase,IWriter* output) const
{
    DnaMetaData* pDna1;
    DnaMetaData* pDna2 = NULL;
    size_t pos;

    if ((*m_pParams)[1][0] == '@')
    {
        pDna1 = dataBase->findDnaByName((*m_pParams)[1].substr(1));
    }
    else
    {
        std::istringstream in((*m_pParams)[1].substr(1));
        size_t id;
        in >> id;
        pDna1 = dataBase->findDnaById(id);
    }

    if ((*m_pParams)[2][0] == '@')
    {
        pDna2 = dataBase->findDnaByName((*m_pParams)[2].substr(1));
    }
    else if ((*m_pParams)[2][0] == '#')
    {
        std::istringstream in((*m_pParams)[2].substr(1));
        size_t id;
        in >> id;
        pDna2 = dataBase->findDnaById(id);
    }

    if (pDna2)
    {
        pos = (pDna1 -> getDnaSequence()).find(pDna2->getDnaSequence());
    }
    else
    {
        pos = (pDna1 -> getDnaSequence()).find((*m_pParams)[2]);
    }


    std::stringstream out;
    out << pos;
    output -> write(out.str().c_str());

}



bool FindCommand::is_valid()
{
    return 3 == (*m_pParams).getSize()
           && ((*m_pParams)[1][0] == '@' || ((*m_pParams)[1][0] == '#' && (*m_pParams)[1].substr(1).find_first_not_of("0123456789") == std::string::npos))
           && ((*m_pParams)[2][0] != '#' || (*m_pParams)[2].substr(1).find_first_not_of("0123456789") == std::string::npos);
}
