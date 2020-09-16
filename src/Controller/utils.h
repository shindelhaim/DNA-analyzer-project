#ifndef SRC_UTILS_H
#define SRC_UTILS_H

#include <string>

class DnaMetaData;

class Utils
{


public:
    static std::string getShortDnaMetaDataFormat(const DnaMetaData* dnaMetaData);
    static bool isNumber(const std::string& str);
};



#endif //SRC_UTILS_H
