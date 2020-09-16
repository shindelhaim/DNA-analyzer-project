#include "find_command.h"
#include <stdexcept>
#include <sstream>
#include <string>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../parser_params.h"
#include "../../../Model/DNA_meta_data.h"
#include "../../../Model/DNA_sequence.h"
#include "../../utils.h"

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
    const DnaSequence* pDna1 = NULL;
    const DnaSequence* pDna2 = NULL;
    bool isAllocate = false;
    size_t pos;

    if ((*m_pParams)[1][0] == '@')
    {
        pDna1 = & ((dataBase -> findDnaByName((*m_pParams)[1].substr(1)))->getDnaSequence());
    }
    else if((*m_pParams)[1][0] == '#')
    {
        std::istringstream in((*m_pParams)[1].substr(1));
        size_t id;
        in >> id;
        pDna1 = & ((dataBase -> findDnaById(id))->getDnaSequence());
    }
    else
    {
        pDna1 = new DnaSequence((*m_pParams)[1]);
        isAllocate = true;
    }

    if ((*m_pParams)[2][0] == '@')
    {
        pDna2 = & ((dataBase -> findDnaByName((*m_pParams)[2].substr(1)))->getDnaSequence());
    }
    else if ((*m_pParams)[2][0] == '#')
    {
        std::istringstream in((*m_pParams)[2].substr(1));
        size_t id;
        in >> id;
        pDna2 = & ((dataBase -> findDnaById(id))->getDnaSequence());
    }

    if (pDna2)
    {
        pos = pDna1 -> find(*pDna2);
    }
    else
    {
        pos = pDna1 -> find((*m_pParams)[2]);
    }

    std::stringstream out;
    out << pos;
    output -> write(out.str().c_str());

    if(isAllocate)
    {
        delete pDna1;
    }

}



bool FindCommand::is_valid()
{
    return 3 == (*m_pParams).getSize()
           && ((*m_pParams)[1][0] != '#' || Utils::isNumber((*m_pParams)[1].substr(1)))
           && ((*m_pParams)[2][0] != '#' || Utils::isNumber((*m_pParams)[2].substr(1)));
}
