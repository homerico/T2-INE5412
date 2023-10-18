#ifndef T2_FIFO_H
#define T2_FIFO_H


#include "PageReplacementAlgorithm.h"
#include "RAM.h"

class FIFO : public PageReplacementAlgorithm {

public:
    FIFO(RAM *ram);

    int getPageFaults();
};


#endif //T2_FIFO_H
