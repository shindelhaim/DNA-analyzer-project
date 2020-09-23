#include "rename_command.h"
#include <stdexcept>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../utils.h"

void RenameCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if (!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }
}


void RenameCommand::execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const
{
    DnaMetaData* pDna;
    std::string name = (*m_pParams)[2].substr(1);

    pDna = Utils::findDnaMateData(dataBase, (*m_pParams)[1][0], (*m_pParams)[1].substr(1));

    if(dataBase->isNameExist(name))
    {
        throw std::invalid_argument("THE NAME IS EXIST IN DATABASE");
    }

    pDna ->setName(name);
    pDna -> setStatus(MODIFIED);

    output->write("--- renamed ---");
}



bool RenameCommand::is_valid()
{
    return 3 == (*m_pParams).getSize() && ('@' == ((*m_pParams)[1][0]) || (( '#' == (*m_pParams)[1][0]) && Utils::isNumber((*m_pParams)[1].substr(1))))
    && ('@' == (*m_pParams)[2][0]);
}