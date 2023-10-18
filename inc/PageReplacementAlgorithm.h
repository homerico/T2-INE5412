#ifndef T2_ALGORITHM_H
#define T2_ALGORITHM_H


#include "RAM.h"

class PageReplacementAlgorithm {
public:
    enum Algorithm {
        FIFO, LRU, OPT
    };
protected:
    RAM *ram;
    int pageFaults;
};


#endif //T2_ALGORITHM_H
