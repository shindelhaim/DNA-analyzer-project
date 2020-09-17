#include <stdexcept>
#include <sstream>
#include "new_command.h"
#include "../../../Model/DB_DNA_sequence.h"
#include "../../parser_params.h"
#include "../../../Model/DNA_meta_data.h"

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
    if(3 == (*m_pParams).getSize())
    {
        tempName = (*m_pParams)[2].substr(1);

    }
    if(2 == (*m_pParams).getSize())
    {
        std::stringstream out;
        out << "seq" << s_countDefault;
        ++s_countDefault;
        tempName = out.str();
    }
    dnaMetaData = new DnaMetaData((*m_pParams)[1],getValidName(tempName,dataBase));
    dataBase->addNewDna(dnaMetaData);

    output->write((dnaMetaData->getDnaDataFormat()).c_str());
}



bool NewCommand::is_valid()
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && (*m_pParams)[2][0] == '@');
}
