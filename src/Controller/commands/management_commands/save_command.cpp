#include <stdexcept>
#include "sstream"
#include <cstdlib>
#include "save_command.h"
#include "../../../Model/DB_DNA_sequence.h"
#include "../../../Model/DNA_meta_data.h"
#include "../../../View/writer/file_writer.h"
#include "../../utils.h"

void SaveCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if (!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }
}


void SaveCommand::execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const
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

    dataBase->moveStatus(pDna,UP_TO_DATA);

    std::string nameFolder;
    if((*m_pParams).getSize() == 3)
    {
        nameFolder = (*m_pParams)[2];
    }
    else
    {
        nameFolder = pDna->getName();
    }

    FileWriter fileToSave("../Model/dna_sequence_files/saved_dna/" + nameFolder +  + ".rawdna");
    fileToSave.write(pDna->getDnaDataFormat().c_str());
}



bool SaveCommand::is_valid()
{
    return (2 == (*m_pParams).getSize() || 3 == (*m_pParams).getSize()) && ((*m_pParams)[1][0] == '@'|| (((*m_pParams)[1][0] == '#') && Utils::isNumber((*m_pParams)[1].substr(1))));
}