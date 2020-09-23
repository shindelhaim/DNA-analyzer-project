#ifndef SRC_USER_INTERFACE_H
#define SRC_USER_INTERFACE_H

#include "../../Controller/callback.h"
#include "../../Controller/system_manager.h"

class IReader;
class IWriter;
class DataBaseDnaSequence;


class UI
{
public:
    virtual void run(DataBaseDnaSequence* dataBaseDnaSequence,Callback<SystemManager>& callback ,IReader* input, IWriter* output) = 0;
    virtual ~UI(){}
};


#endif //SRC_USER_INTERFACE_H
