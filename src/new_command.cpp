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
    std::string name;
    if(3 == (*m_pParams).getSize())
    {
        name = (*m_pParams)[2];
    }
    else
    {
        name = "seq" +
    }

    DataBaseDnaSequence::addNewDna(new DnaMetaData(name,NEW,(*m_pParams)[1]);

}



bool NewCommand::is_valid() {
    return true;
}
