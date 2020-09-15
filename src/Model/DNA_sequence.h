#ifndef DNA_CLASS_DNASEQUENCE_H
#define DNA_CLASS_DNASEQUENCE_H

#include <list>
#include "../View/i_reader.h"
#include "../View/i_writer.h"

class DnaSequence
{
private:

    class NucleotideAsChar
    {
    public:
        NucleotideAsChar() { m_nucleotide = '\0'; }
        char operator=(char nucleotide);
        operator char();
        static bool isValidNucleotide(char nucleotide, const char *validSequence = "ACTG");
    private:
        char m_nucleotide;
    };
    typedef NucleotideAsChar Nucleotide;

public:

    DnaSequence(const char *str);
    DnaSequence(const std::string& dnaSeq);
    DnaSequence(const IReader& readerObj);
    ~DnaSequence();
    DnaSequence(const DnaSequence& dnaSeq);

    DnaSequence& operator=(const DnaSequence& dnaSeq);
    Nucleotide& operator[](size_t index);

    friend std::ostream& operator<<(std::ostream& out, const DnaSequence& dna);
    friend bool operator==(const DnaSequence& dnaSeq1, const DnaSequence& dnaSeq2);
    friend bool operator!=(const DnaSequence& dnaSeq1, const DnaSequence& dnaSeq2);

    size_t length() const ;
    DnaSequence pairing() const;
    DnaSequence slice(size_t indexStart,size_t indexEnd) const;
    size_t find(const DnaSequence& subDnaSequence) const;
    size_t count(const DnaSequence& subDnaSequence) const ;
    std::list<size_t> findAll(const DnaSequence& subDnaSequence) const;
    std::list<DnaSequence> findConsensusSequences() const;
    void writeDna(const IWriter& writerObj) const;



private:

    static bool isValidDnaSequence(const char *dnaSequence, const char *validSequence = "ACTG");
    void initDataDnaSequence(const char *dnaSequence);
    void copyCharSequenceToNucleotides(const char *dnaSequence);
    const char* getDnaSequenceAsStr() const ;
    explicit DnaSequence(size_t length);
    void createConsensusSequences(std::list<DnaSequence>& consensusSequences,std::list<size_t>& indexesStartCode ,std::list<size_t>& indexesEndCode) const;


    Nucleotide* m_dnaSequence;
    size_t m_length;


};



#endif //DNA_CLASS_DNASEQUENCE_H
