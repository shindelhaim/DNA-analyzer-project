#include <stdexcept>
#include <sstream>
#include "new_command.h"
#include "../../../Model/DB_DNA_sequence.h"
#include "../../parser_params.h"
#include "../../../Model/DNA_meta_data.h"
#include "../../utils.h"

void NewCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void NewCommand::execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const
{
    DnaMetaData* dnaMetaData;
    std::string tempName;
    static size_t s_countDefault = 1;
    bool isSentName = 3 == (*m_pParams).getSize();

    if(isSentName)
    {
        tempName = (*m_pParams)[2].substr(1);
    }
    else
    {
        tempName = "seq" + Utils::castNumToStr(s_countDefault++);
    }

    try
    {
        dnaMetaData = new DnaMetaData((*m_pParams)[1],Utils::getValidName(tempName,dataBase));
    }
    catch (const std::invalid_argument& e)
    {
        if(!isSentName)
        {
            --s_countDefault;
        }
        throw e;
    }

    dataBase->addNewDna(dnaMetaData);

    output->write((dnaMetaData->getDnaDataFormat()).c_str());
}



bool NewCommand::is_valid()
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && (*m_pParams)[2][0] == '@');
}
