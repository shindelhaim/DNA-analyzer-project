#include "len_command.h"
#include <stdexcept>
#include <sstream>
#include <string>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../utils.h"

void LenCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void LenCommand::execute(DataBaseDnaSequence* dataBase, IReader* input, IWriter* output) const
{
    size_t lenDna;
    const DnaSequence* pDna;

    pDna = &(Utils::findDnaMateData(dataBase, (*m_pParams)[1][0], (*m_pParams)[1].substr(1))->getDnaSequence());

    lenDna = pDna -> length();
    output->write(Utils::castNumToStr(lenDna).c_str());
}



bool LenCommand::is_valid()
{
    return 2 == (*m_pParams).getSize()
           && ((*m_pParams)[1][0] == '@' || ((*m_pParams)[1][0] == '#' && Utils::isNumber(((*m_pParams)[1]).substr(1))));
}
