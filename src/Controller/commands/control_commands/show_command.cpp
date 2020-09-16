#include "show_command.h"
#include <stdexcept>
#include <sstream>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../../Model/DNA_meta_data.h"
#include "../../utils.h"

void ShowCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void ShowCommand::execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const
{
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


    output->write(getSpecifiesFormat(pDna).c_str());
}



bool ShowCommand::is_valid()
{
    return (2 == (*m_pParams).getSize() || 3 == (*m_pParams).getSize() && Utils::isNumber((*m_pParams)[2]))
    && ((*m_pParams)[1][0] == '@' || ((*m_pParams)[1][0] == '#' && Utils::isNumber(((*m_pParams)[1]).substr(1))));
}

std::string ShowCommand::getSpecifiesFormat(const DnaMetaData *pDnaMetaData) const
{
    std::string status;
    std::stringstream out;
    size_t numChars;

    if(m_pParams->getSize() == 3)
    {
        std::istringstream in((*m_pParams)[2]);
        in >> numChars;
    }
    else
    {
        numChars = 99;
    }



    switch (pDnaMetaData->getStatus())
    {
        case UP_TO_DATA:
            status = "up_to_data";
            break;
        case MODIFIED:
            status = "modified";
            break;
        case NEW:
            status = "new";
            break;
    }

    out << "[" << pDnaMetaData->getId() << "] " << pDnaMetaData -> getName() << ' ' << status <<std::endl ;
    size_t i = 0;
    size_t endIndex;
    size_t len = pDnaMetaData ->getDnaSequence().length();

    len < numChars ? numChars = len : numChars = numChars ;
    numChars < 99 ? endIndex = numChars : endIndex = 99;

    out << (pDnaMetaData->getDnaSequence()).slice(i , endIndex) << std::endl;

    for(i = 99 ;i < numChars; i += 99 )
    {
        out<< (pDnaMetaData->getDnaSequence()).slice(i , i + 99) << std::endl;
    }

    return out.str();

}



