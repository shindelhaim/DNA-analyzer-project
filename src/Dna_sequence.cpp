#include <string>
#include <cstring>// for strcpy
#include <fstream>
#include <iostream>
#include <algorithm>
#include <list>
#include "Dna_sequence.h"

char DnaSequence::NucleotideAsChar::operator=(char nucleotide)
{

    if(!isValidNucleotide(nucleotide))
    {
        throw std::invalid_argument("Nucleotide is not valid");
    }

    m_nucleotide = nucleotide;
    return m_nucleotide;
}

DnaSequence::NucleotideAsChar::operator char() {
    return m_nucleotide;
}

bool DnaSequence::NucleotideAsChar::isValidNucleotide(char nucleotide, const char *validNucleotides)
{
    int i;
    int length = strlen(validNucleotides);
    for(i=0; i<length;i++)
    {
        if(nucleotide == validNucleotides[i])
        {
            return true;
        }
    }

    return false;
}

DnaSequence::DnaSequence(const char *str)
{
    initDataDnaSequence(str);
}

DnaSequence::DnaSequence(const std::string& str)
{
    initDataDnaSequence(str.c_str());
}

DnaSequence::DnaSequence(const IReader & readerObj)
{
    initDataDnaSequence(readerObj.read().c_str());
}

DnaSequence::~DnaSequence()
{
    delete[] m_dnaSequence;
}

DnaSequence::DnaSequence(const DnaSequence & dnaSeq)
{
    initDataDnaSequence(dnaSeq.getDnaSequenceAsStr());

}

DnaSequence& DnaSequence::operator=(const DnaSequence & dnaSeq)
{
    if(m_dnaSequence == dnaSeq.m_dnaSequence)
    {
        return *this;
    }

    delete(m_dnaSequence);
    initDataDnaSequence(dnaSeq.getDnaSequenceAsStr());//need to cast const char *
    m_length = dnaSeq.m_length;

    return *this;
}

bool operator==(const DnaSequence& dnaSeq1 ,const DnaSequence& dnaSeq2){

    return strcmp(dnaSeq1.getDnaSequenceAsStr(),dnaSeq2.getDnaSequenceAsStr()) == 0;
}

bool operator!=(const DnaSequence& dnaSeq1 ,const DnaSequence& dnaSeq2){

    return strcmp(dnaSeq1.getDnaSequenceAsStr(),dnaSeq2.getDnaSequenceAsStr()) != 0;
}

DnaSequence::Nucleotide& DnaSequence::operator[](size_t index)
{

    if(index >= length())
    {
        throw std::out_of_range("The index is out of range from the dna-sequence");
    }

    return m_dnaSequence[index];
}

size_t DnaSequence::length() const
{
    return m_length;
}

DnaSequence DnaSequence::pairing() const
{
    DnaSequence pair(m_length);
    size_t i = 0;
    for(i = 0; i < m_length;i++)
    {
        if(m_dnaSequence[i] == 'A')
        {
            pair[m_length-i-1] = 'T';
        }
        else if(m_dnaSequence[i] == 'T')
        {
            pair[m_length-i-1] = 'A';
        }
        else if(m_dnaSequence[i] == 'G')
        {
            pair[m_length-i-1] = 'C';
        }
        else if(m_dnaSequence[i] == 'C')
        {
            pair[m_length-i-1] = 'G';
        }
    }

    return pair;

}

DnaSequence DnaSequence::slice(size_t indexStart, size_t indexEnd)const
{
    indexEnd = std::min(indexEnd,m_length);
    if(indexStart > indexEnd)
    {
        throw std::invalid_argument("start index bigger than end index");
    }
    DnaSequence subDnaSequence(indexEnd - indexStart);
    size_t i ,j;
    for(i=indexStart,j=0;i < indexEnd; i++ ,j++)
    {
        subDnaSequence[j] = m_dnaSequence[i];
    }
    return subDnaSequence;
}

size_t DnaSequence::find(const DnaSequence& subDnaSequence) const
{
    size_t index;
    index = ((std::string)getDnaSequenceAsStr()).find((std::string)subDnaSequence.getDnaSequenceAsStr());
    if(index == std::string::npos)
        return m_length;
    return index;

}

size_t DnaSequence::count(const DnaSequence& subDnaSequence) const
{
    DnaSequence tempSequence = *this;
    size_t count = 0;
    size_t indexFind = find(subDnaSequence);

    if(indexFind == 0)
    {
        count++;
    }

    size_t i;
    for(i =1; i < m_length && indexFind != tempSequence.m_length; i++)
    {
        tempSequence = tempSequence.slice(1,tempSequence.m_length);
        indexFind = tempSequence.find(subDnaSequence);
        if(indexFind == 0)
        {
            count++;
        }
    }

    return count;

}

std::list<size_t> DnaSequence::findAll(const DnaSequence& subDnaSequence) const
{
    std::list<size_t> foundIndexes;
    DnaSequence tempSequence = *this;
    size_t indexFind = find(subDnaSequence);

    if(indexFind == 0)
    {
        foundIndexes.push_back(0);
    }
    size_t i;

    for(i =1; i < m_length && indexFind != tempSequence.m_length; i++)
    {
        tempSequence = tempSequence.slice(1,tempSequence.m_length);
        indexFind = tempSequence.find(subDnaSequence);
        if(indexFind == 0)
        {
            foundIndexes.push_back(i);
        }
    }

    return foundIndexes;
}

std::list<DnaSequence> DnaSequence::findConsensusSequences() const
{
    std::list<size_t> indexesStartCode = findAll("ATG");
    std::list<size_t> indexesEndCode1 = findAll("TAG");
    std::list<size_t> indexesEndCode2 = findAll("TAA");
    std::list<size_t> indexesEndCode3 = findAll("TGA");
    std::list<DnaSequence> consensusSequences;
    createConsensusSequences(consensusSequences,indexesStartCode,indexesEndCode1);
    createConsensusSequences(consensusSequences,indexesStartCode,indexesEndCode2);
    createConsensusSequences(consensusSequences,indexesStartCode,indexesEndCode3);

    return consensusSequences;


}

void DnaSequence::createConsensusSequences(std::list<DnaSequence>& consensusSequences,std::list<size_t>&  indexesStartCode ,std::list<size_t>& indexesEndCode) const
{
    std::list<size_t>::iterator iterStart;
    std::list<size_t>::iterator iterEnd;

    for(iterStart = indexesStartCode.begin();iterStart != indexesStartCode.end();iterStart++)
    {
        for(iterEnd = indexesEndCode.begin();iterEnd != indexesEndCode.end();iterEnd++)
        {
            if(*iterStart < *iterEnd && (*iterEnd - *iterStart) % 3 == 0)
            {
                consensusSequences.push_back(slice(*iterStart,*iterEnd + 3));
            }
        }
    }
}

void DnaSequence::writeDna(const IWriter& writerObj) const
{
    writerObj.write(getDnaSequenceAsStr());
}

bool DnaSequence::isValidDnaSequence(const char *dnaSequence, const char *validSequence)
{
    return strlen(dnaSequence) == strspn(dnaSequence, validSequence);
}

void DnaSequence::initDataDnaSequence(const char *dnaSequence)
{

    if (!dnaSequence || ! isValidDnaSequence(dnaSequence))
    {
        throw std::invalid_argument("DnaSequence is not valid");
    }
    m_length = strlen(dnaSequence);
    m_dnaSequence = new DnaSequence::Nucleotide[strlen(dnaSequence)+1];
    copyCharSequenceToNucleotides(dnaSequence);
}

void DnaSequence::copyCharSequenceToNucleotides(const char *dnaSequence)
{
    size_t i;
    for(i = 0; i < m_length;i++)
    {
        m_dnaSequence[i] = dnaSequence[i];
    }

}

const char*  DnaSequence::getDnaSequenceAsStr() const
{
    return (const char *)m_dnaSequence;
}

DnaSequence::DnaSequence(size_t length)
{
    m_dnaSequence = new DnaSequence::Nucleotide[length + 1];
    m_length =length;
}

std::ostream& operator<<(std::ostream& out, const DnaSequence& dnaSeq)
{
    out << "DNA: " << dnaSeq.getDnaSequenceAsStr();
    return out;
}








