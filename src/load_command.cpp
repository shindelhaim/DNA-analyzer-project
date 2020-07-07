#include "load_command.h"
#include <stdexcept>
#include <sstream>
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


void LoadCommand::execute(DataBaseDnaSequence* dataBase,IWriter* output) const
{
    DnaMetaData* dnaMetaData;
    FileReader fileReader((*m_pParams)[1]);
    fileReader.initInput();
    if(3 == (*m_pParams).getSize())
    {

        dnaMetaData = new DnaMetaData(fileReader.read(),(*m_pParams)[2].substr(1));
        dataBase->addNewDna(dnaMetaData);
    }
    if(2 == (*m_pParams).getSize())
    {
        size_t pointIndex = (*m_pParams)[1].find('.');
        dnaMetaData = new DnaMetaData(fileReader.read(),(*m_pParams)[1].substr(0,pointIndex));
        dataBase->addNewDna(dnaMetaData);
    }



    output->write(getDnaMetaDataAsStr(dnaMetaData).c_str());
}



bool LoadCommand::is_valid()
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && (*m_pParams)[2][0] == '@');
}

std::string LoadCommand::getDnaMetaDataAsStr(const DnaMetaData* dnaMetaData)
{
    std::stringstream out;
    out << "[" << dnaMetaData->getId() << "] " << dnaMetaData->getName() <<": ";
    size_t lengthDnaSeq = (dnaMetaData->getDnaSequence()).length();
    if( lengthDnaSeq > 40)
    {
        out << (dnaMetaData->getDnaSequence()).slice(0,32) << "..." <<(dnaMetaData->getDnaSequence()).slice(lengthDnaSeq-3,lengthDnaSeq);
    }
    else
    {
        out << (dnaMetaData->getDnaSequence());
    }
    return out.str();
}
