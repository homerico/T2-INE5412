#ifndef T2_INE5412_TLB_H
#define T2_INE5412_TLB_H

#include "RAM.h"
#include "PageReplacementAlgorithm.h"

class TLB {
public:
    TLB(int tlbSize);

    ~TLB() = default;

    struct TLBufferEntry {
        bool valid;
        bool modified;
        int pid;
        int virtualPage;
        int pageFrame;
    };

    int getTranslation(int virtualAddr, int processId);

private:
    int tlbSize;
    TLBufferEntry* table;
};


#endif //T2_INE5412_TLB_H
