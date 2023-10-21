#ifndef T2_LRU_H
#define T2_LRU_H


#include "PageReplacementAlgorithm.h"
#include "RAM.h"

class LRU : public PageReplacementAlgorithm {

public:
    LRU(RAM *ram);
};


#endif //T2_LRU_H
