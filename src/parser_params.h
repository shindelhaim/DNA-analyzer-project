#ifndef SRC_PARSER_PARAMS_H
#define SRC_PARSER_PARAMS_H

#include <vector>
#include <string>

class IReader;

class ParserParams
{
public:
    void parseInput(const IReader& inputToParse, char delimiter = ' ');
    const std::string& operator[](size_t index)const;
    size_t getSize() const{return m_size;}

private:
    std::vector<std::string> m_params;
    size_t m_size;
};

#endif //SRC_PARSER_PARAMS_H
