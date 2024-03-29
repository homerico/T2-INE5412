#ifndef T2_INE5412_MMU_H
#define T2_INE5412_MMU_H

#include "TLB.h"

class MMU {
public:
    MMU(TLB* tlb);

    ~MMU() = default;

    int retreivePhysicalAddress(int pid, int virtualAddr);

private:
    TLB *tlb;
};


#endif //T2_INE5412_MMU_H
