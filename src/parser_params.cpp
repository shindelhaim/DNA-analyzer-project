#include <sstream>
#include <stdio.h>
#include "parser_params.h"
#include "IReader.h"


void ParserParams::parseInput(const IReader& inputToParse, char delimiter)
{
    size_t i;
    std::stringstream data(inputToParse.read());
    std::string word;
    for(i = 0 ;getline(data,word,delimiter);++i)
    {
        m_params[i] = word;
    }

}

const std::string& ParserParams::operator[](size_t index) const
{
    return m_params[index];
}
