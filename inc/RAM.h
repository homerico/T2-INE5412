#ifndef T2_RAM_H
#define T2_RAM_H


#include <vector>
#include "PageFrame.h"
#include "PageReplacementAlgorithm.h"

class RAM {

public:
    RAM(int frames);
    ~RAM();

private:
    std::vector<PageFrame *> pageFrames;
};


#endif //T2_RAM_H
