#include "dup_command.h"
#include <stdexcept>
#include <sstream>

#include "../../../Model/DB_DNA_sequence.h"
#include "../../../Model/DNA_meta_data.h"
#include "../../utils.h"

void DupCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void DupCommand::execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const
{
    DnaMetaData* dnaMetaData;
    std::string tempName;
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

    if(3 == (*m_pParams).getSize())
    {
        tempName = (*m_pParams)[2].substr(1);

    }
    if(2 == (*m_pParams).getSize())
    {
        tempName = pDna->getName();
    }
    dnaMetaData = new DnaMetaData(pDna->getDnaSequence(),getValidName(tempName,dataBase));
    dataBase->addNewDna(dnaMetaData);

    output->write((dnaMetaData->getDnaDataFormat()).c_str());
}



bool DupCommand::is_valid()
{
    return (2 == (*m_pParams).getSize() ||
    (3 == (*m_pParams).getSize() && (*m_pParams)[2][0] == '@'))
    && ((*m_pParams)[1][0] == '@' || ((*m_pParams)[1][0] == '#') && Utils::isNumber(((*m_pParams)[1]).substr(1)));
}
