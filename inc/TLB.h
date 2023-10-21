#ifndef T2_INE5412_TLB_H
#define T2_INE5412_TLB_H

#include "RAM.h"
#include "PageReplacementAlgorithm.h"

class TLB {
public:
    TLB(RAM *ram, PageReplacementAlgorithm::Algorithm algorithm);

    ~TLB() = default;

    int getPageFaults();

    PageFrame *getData(int pageNeeded, int processId);

private:
    RAM *ram;
    int pageFaults;
    PageReplacementAlgorithm *algorithm;
    // ordem das colunas: valido, pagina, moldura
    int table[][3];
};


#endif //T2_INE5412_TLB_H
