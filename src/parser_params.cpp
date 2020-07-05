#include <sstream>
#include <stdio.h>
#include <iostream>
#include "parser_params.h"
#include "IReader.h"


void ParserParams::parseInput(const IReader& inputToParse, char delimiter)
{
    std::string data = inputToParse.read();
    size_t i,pos,size = m_params.size();

    for(i = 0 ;i < size && ((pos = data.find(delimiter) )!= std::string::npos);++i)
    {
        m_params[i] = data.substr(0,pos);
        data.erase(0,pos+1);
    }
    while((pos = data.find(delimiter) )!= std::string::npos)
    {
        m_params.push_back(data.substr(0,pos));
        data.erase(0,pos+1);
    }
    m_params.push_back(data.substr(0,pos));

}

const std::string& ParserParams::operator[](size_t index) const
{
    return m_params[index];
}
