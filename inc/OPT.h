#ifndef T2_OPT_H
#define T2_OPT_H


#include "PageReplacementAlgorithm.h"
#include "RAM.h"

class OPT : public PageReplacementAlgorithm {

public:
    OPT(RAM *ram);

    int getPageFaults();
};


#endif //T2_OPT_H
