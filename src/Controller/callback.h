#ifndef SRC_CALLBACK_H
#define SRC_CALLBACK_H

#include "parser_params.h"
class IReader;
class IWriter;

template < class cInstance >
class Callback
{
public:
    typedef void(cInstance::*tFunc)(ParserParams&, IReader* input, IWriter* output);
    Callback(cInstance* obj,tFunc func);
    void operator()(ParserParams&, IReader* input, IWriter* output);

private:
    cInstance* m_obj;
    tFunc m_func;


};

template<class cInstance>
inline Callback<cInstance>::Callback(cInstance *obj, Callback::tFunc func) :m_obj(obj),m_func(func)
{

}

template<class cInstance>
inline void Callback<cInstance>::operator()(ParserParams & params, IReader* input, IWriter* output)
{
    (m_obj ->* m_func)(params, input, output);
}


#endif //SRC_CALLBACK_H
