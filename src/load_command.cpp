#include "load_command.h"
#include <stdexcept>
#include "DB_DNA_sequence.h"
#include "parser_params.h"
#include "DNA_meta_data.h"
#include "screen_writer.h"
#include "FileReader.h"

LoadCommand::LoadCommand(const ParserParams &parameters) :CreationCommand(parameters)
{
    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }
}


void LoadCommand::execute() const
{
    DnaMetaData* dnaMetaData;
    FileReader fileReader((*m_pParams)[1]);
    if(3 == (*m_pParams).getSize())
    {
        dnaMetaData = new DnaMetaData(fileReader.read(),(*m_pParams)[2].substr(1));
        DataBaseDnaSequence::addNewDna(dnaMetaData);
    }
    if(2 == (*m_pParams).getSize())
    {
        size_t pointIndex = (*m_pParams)[1].find('.');
        dnaMetaData = new DnaMetaData(fileReader.read(),(*m_pParams)[1].substr(0,pointIndex));
        DataBaseDnaSequence::addNewDna(dnaMetaData);
    }

    ScreenWriter output;
    output.write((dnaMetaData->getDnaData()).c_str());
}



bool LoadCommand::is_valid()
{
    return 2 == (*m_pParams).getSize() || 3 == (*m_pParams).getSize();
}
