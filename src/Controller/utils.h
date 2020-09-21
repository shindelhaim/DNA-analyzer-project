#ifndef SRC_UTILS_H
#define SRC_UTILS_H

#include <string>
#include <list>

class DnaMetaData;
class DataBaseDnaSequence;

class Utils
{


public:
    static std::string getShortDnaMetaDataFormat(const DnaMetaData* dnaMetaData);
    static std::string getValidName(const std::string& name, DataBaseDnaSequence* dataBase);
    static DnaMetaData* findDnaMateData(DataBaseDnaSequence* db, char c, const std::string& str);

    static bool isNumber(const std::string& str);
    static size_t castStrToNum(const std::string& str);
    static std::string castNumToStr(size_t);
    static const std::string castNumsListToString(const std::list<size_t>& list);

};



#endif //SRC_UTILS_H
