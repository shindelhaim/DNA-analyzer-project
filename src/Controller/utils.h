#ifndef SRC_UTILS_H
#define SRC_UTILS_H

#include <string>

class DnaMetaData;
class DataBaseDnaSequence;

class Utils
{


public:
    static std::string getShortDnaMetaDataFormat(const DnaMetaData* dnaMetaData);
    static bool isNumber(const std::string& str);
    static std::string getValidName(const std::string& name, DataBaseDnaSequence* dataBase);

};



#endif //SRC_UTILS_H
