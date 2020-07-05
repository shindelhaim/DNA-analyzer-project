#include <sstream>
#include <stdio.h>
#include <iostream>
#include "parser_params.h"
#include "IReader.h"


void ParserParams::parseInput(const IReader& inputToParse, char delimiter)
{
    std::string data = inputToParse.read();
    size_t i,pos,sizeParameters = m_params.size();

    pos = data.find(delimiter);
    for(i = 0 ; i < sizeParameters && (pos != std::string::npos); ++i)
    {
        m_params[i] = data.substr(0,pos);
        data.erase(0,pos+1);
        pos = data.find(delimiter);
    }

    for(;pos != std::string::npos;++i)
    {
        m_params.push_back(data.substr(0,pos));
        data.erase(0,pos+1);
        pos = data.find(delimiter);
    }

    if(i < sizeParameters)
    {
        m_params[i] = data;
    }
    else
    {
        m_params.push_back(data);
    }


    m_size = i+1;

}

const std::string& ParserParams::operator[](size_t index) const
{
    if(index >= m_size)
    {
        throw std::out_of_range("OUT OF RANGE OF PARAMETERS' NUMBER");
    }


    return m_params[index];
}
