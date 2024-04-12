#include "SmartPointer.h"

SmartPointer::SmartPointer(const SmartPointer &sptr)
{
    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if(pointer)
        (*ref_cnt)++;
}

void SmartPointer::assign(const SmartPointer &sptr)
{
    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if(pointer)(*ref_cnt)++;
}

SmartPointer::~SmartPointer()
{
    if (pointer == 0)
        return;
    else if(*ref_cnt==1)
        delete pointer;
    else 
        (*ref_cnt)--;

    pointer = 0;
    ref_cnt = 0;
}
