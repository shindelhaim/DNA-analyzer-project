#ifndef SRC_UTILS_H
#define SRC_UTILS_H

#include <string>

class DnaMetaData;

class Utils
{


public:
    static std::string getShortDnaMetaDataFormat(const DnaMetaData* dnaMetaData);
};



#endif //SRC_UTILS_H
