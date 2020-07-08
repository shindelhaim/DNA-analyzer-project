#include <stdexcept>
#include "sstream"
#include <cstdlib>
#include "save_command.h"
#include "DB_DNA_sequence.h"
#include "parser_params.h"
#include "DNA_meta_data.h"
#include "file_writer.h"

SaveCommand::SaveCommand(const ParserParams &parameters) :ManagementCommands(parameters)
{
    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }
}


void SaveCommand::execute(DataBaseDnaSequence* dataBase,IWriter* output) const
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

    if((*m_pParams).getSize() == 3)
    {
        FileWriter fileToSave((*m_pParams)[2]);
        fileToSave.write(pDna->getDnaData().c_str());
    }
    else
    {
        FileWriter fileToSave(pDna->getName() + ".rawdna");
        fileToSave.write(pDna->getDnaData().c_str());
    }

}



bool SaveCommand::is_valid()
{
    return (2 == (*m_pParams).getSize() || 3 == (*m_pParams).getSize()) && ((*m_pParams)[1][0] == '@'|| (*m_pParams)[1][0] == '#') ;
}