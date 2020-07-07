#ifndef SRC_TERMINAL_H
#define SRC_TERMINAL_H

class IReader;
class IWriter;
class DataBaseDnaSequence;

class Terminal
{
public:
    static void start(DataBaseDnaSequence* dataBaseDnaSequence, IReader* input, IWriter* output);
};





#endif //SRC_TERMINAL_H
