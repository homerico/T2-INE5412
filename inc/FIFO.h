#ifndef T2_FIFO_H
#define T2_FIFO_H

#include <queue>
#include "PageReplacementAlgorithm.h"

class FIFO : public PageReplacementAlgorithm {
public:
    FIFO(unsigned accessListMaxSize);

    ~FIFO() = default;

    std::tuple<int,int> findMemory(int nextVirtualAdrrAccess);

    void update(int virtualAddr);

private:
    std::queue<std::tuple<int,int>> accessList;
    unsigned accessListMaxSize;
};


#endif //T2_FIFO_H
