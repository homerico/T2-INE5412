#ifndef T2_LRU_H
#define T2_LRU_H

#include <list>
#include <tuple>
#include "PageReplacementAlgorithm.h"

class LRU : public PageReplacementAlgorithm {
public:
    LRU(unsigned accessListMaxSize);

    std::tuple<int,int> findMemory(int nextVirtualAdrrAccess);

    void update(int virtualMemAccess);

private:
    std::list<int> accessList;
    std::map<int,int> memTranslate;
    unsigned accessListMaxSize;
};

#endif //T2_LRU_H
