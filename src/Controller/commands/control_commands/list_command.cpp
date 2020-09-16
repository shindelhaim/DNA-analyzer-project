#include "list_command.h"
#include <stdexcept>
#include <sstream>
#include "../../../Model/DB_DNA_sequence.h"
#include "../../../Model/DNA_meta_data.h"
#include "../../utils.h"

void ListCommand::initParams(const ParserParams &parameters)
{
    m_pParams = &parameters;

    if(!is_valid())
    {
        throw std::invalid_argument("IVALID PARAMETERS");
    }

}


void ListCommand::execute(DataBaseDnaSequence* dataBase,IWriter* output) const
{
    DnaMetaData* pDnaMetaData;
    const std::vector<size_t> ids = dataBase -> getSortIds();
    std::vector<size_t>::const_iterator iterId;
    char sign;
    std::stringstream out;

    for(iterId = ids.begin();iterId != ids.end();++iterId)
    {
        pDnaMetaData = dataBase -> findDnaById(*iterId);

        switch (pDnaMetaData->getStatus())
        {

            case UP_TO_DATA:
                sign = '-';
                break;
            case MODIFIED:
                sign = '*';
                break;
            case NEW:
                sign = 'o';
                break;
        }

        out << sign << ' ' << Utils::getShortDnaMetaDataFormat(pDnaMetaData) << std::endl;
    }

    output->write(out.str().c_str());
}



bool ListCommand::is_valid()
{
    return 1 == (*m_pParams).getSize();
}


