#include <stdexcept>
#include "new_command.h"
#include "DB_DNA_sequence.h"
#include "Dna_sequence.h"
#include "parser_params.h"
#include "DNA_meta_data.h"

NewCommand::NewCommand(const ParserParams &parameters) :CreationCommand(parameters)
{
    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }
}


void NewCommand::execute() const
{
    if(3 == (*m_pParams).getSize())
    {
        DataBaseDnaSequence::addNewDna(new DnaMetaData((*m_pParams)[1],(*m_pParams)[2].substr(1)));
    }
    if(2 == (*m_pParams).getSize())
    {
        DataBaseDnaSequence::addNewDna(new DnaMetaData((*m_pParams)[1]));
    }
}



bool NewCommand::is_valid() {
    return true;
}
