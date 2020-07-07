#include <stdexcept>
#include "new_command.h"
#include "DB_DNA_sequence.h"
#include "parser_params.h"
#include "DNA_meta_data.h"
#include "screen_writer.h"

NewCommand::NewCommand(const ParserParams &parameters) :CreationCommand(parameters)
{
    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }
}


void NewCommand::execute() const
{
    DnaMetaData* dnaMetaData;
    if(3 == (*m_pParams).getSize())
    {
        dnaMetaData = new DnaMetaData((*m_pParams)[1],(*m_pParams)[2].substr(1));
        DataBaseDnaSequence::addNewDna(dnaMetaData);
    }
    if(2 == (*m_pParams).getSize())
    {
        dnaMetaData = new DnaMetaData((*m_pParams)[1]);
        DataBaseDnaSequence::addNewDna(dnaMetaData);
    }

    ScreenWriter output;
    output.write((dnaMetaData->getDnaData()).c_str());
}



bool NewCommand::is_valid()
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && (*m_pParams)[2][0] == '@');
}