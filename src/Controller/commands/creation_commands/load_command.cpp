#include "load_command.h"
#include <stdexcept>
#include <sstream>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../parser_params.h"
#include "../../../Model/DNA_meta_data.h"
#include "../../../View/screen_writer.h"
#include "../../../View/file_reader.h"
#include "../../utils.h"

void LoadCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }
}


void LoadCommand::execute(DataBaseDnaSequence* dataBase,IWriter* output) const
{
    DnaMetaData* dnaMetaData;
    std::string nameFolder = "../Model/dna_sequence_files/load_dna/" + (*m_pParams)[1];
    FileReader fileReader(nameFolder);
    fileReader.initInput();
    std::string tempName;
    if(3 == (*m_pParams).getSize())
    {
        tempName = (*m_pParams)[2].substr(1);
    }
    if(2 == (*m_pParams).getSize())
    {
        size_t pointIndex = (*m_pParams)[1].find_last_of('.');
        tempName = (*m_pParams)[1].substr(0,pointIndex);
    }

    dnaMetaData = new DnaMetaData(fileReader.read(),getValidName(tempName,dataBase));
    dnaMetaData -> setStatus(UP_TO_DATA);
    dataBase->addNewDna(dnaMetaData);

    output->write(Utils::getShortDnaMetaDataFormat(dnaMetaData).c_str());
}



bool LoadCommand::is_valid()
{
    return 2 == (*m_pParams).getSize() || (3 == (*m_pParams).getSize() && (*m_pParams)[2][0] == '@');
}

