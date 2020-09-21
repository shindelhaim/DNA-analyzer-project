#include "find_all_command.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../utils.h"

void FindAllCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void FindAllCommand::execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const
{
    const DnaMetaData* tempPMetaData;
    const DnaSequence* pDna1;
    const DnaSequence* pDna2;
    bool isAllocate = false;
    std::list<size_t> listIndexes;


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
        listIndexes = pDna1 -> findAll(*pDna2);
    }
    else
    {
        listIndexes = pDna1 -> findAll((*m_pParams)[2]);
    }

    std::stringstream out;
    std::list<size_t>::iterator iterList;
    for(iterList = listIndexes.begin(); iterList != listIndexes.end(); ++iterList)
    {
        out << *iterList << ' ';
    }


    output -> write(out.str().c_str());

    if(isAllocate)
    {
        delete pDna1;
    }

}



bool FindAllCommand::is_valid()
{
    return 3 == (*m_pParams).getSize()
           && ((*m_pParams)[1][0] != '#' || Utils::isNumber((*m_pParams)[1].substr(1)))
           && ((*m_pParams)[2][0] != '#' || Utils::isNumber((*m_pParams)[2].substr(1)));
}