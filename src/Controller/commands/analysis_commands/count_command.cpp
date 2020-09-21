#include "count_command.h"
#include <stdexcept>
#include <string>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../utils.h"

void CountCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void CountCommand::execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const
{
    const DnaMetaData* tempPMetaData;
    const DnaSequence* pDna1;
    const DnaSequence* pDna2;
    bool isAllocate = false;
    size_t numOfAppearance;


    tempPMetaData = Utils::findDnaMateData(dataBase, (*m_pParams)[1][0], (*m_pParams)[1].substr(1));
    if(tempPMetaData)
    {
        pDna1 = &(tempPMetaData -> getDnaSequence());
    }
    else
    {
        pDna1 = new DnaSequence((*m_pParams)[1]);
        isAllocate = true;
    }

    tempPMetaData = Utils::findDnaMateData(dataBase, (*m_pParams)[2][0], (*m_pParams)[2].substr(1));

    if(tempPMetaData)
    {
        pDna2 = &(tempPMetaData -> getDnaSequence());
        numOfAppearance = pDna1 -> count(*pDna2);
    }
    else
    {
        numOfAppearance = pDna1 -> count((*m_pParams)[2]);
    }

    output -> write(Utils::castNumToStr(numOfAppearance).c_str());

    if(isAllocate)
    {
        delete pDna1;
    }

}



bool CountCommand::is_valid()
{
    return 3 == (*m_pParams).getSize()
           && ((*m_pParams)[1][0] != '#' || Utils::isNumber((*m_pParams)[1].substr(1)))
           && ((*m_pParams)[2][0] != '#' || Utils::isNumber((*m_pParams)[2].substr(1)));
}