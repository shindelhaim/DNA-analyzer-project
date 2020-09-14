#ifndef SRC_USER_INTERFACE_H
#define SRC_USER_INTERFACE_H

class IReader;
class IWriter;
class DataBaseDnaSequence;

class UI
{
public:
    virtual void run(DataBaseDnaSequence* dataBaseDnaSequence, IReader* input, IWriter* output) = 0;

};


#endif //SRC_USER_INTERFACE_H
