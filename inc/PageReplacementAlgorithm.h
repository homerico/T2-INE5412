#ifndef T2_ALGORITHM_H
#define T2_ALGORITHM_H

#include <tuple>
#include "RAM.h"
#include "PageTable.h"

class PageReplacementAlgorithm {
public:

    PageReplacementAlgorithm();

    virtual ~PageReplacementAlgorithm();

    void setMemorySpace(RAM::ProcessMemorySpace* pMem) {
        this->pMemSpace = pMem;
    };

    virtual std::tuple<int,int> findMemory(int nextVirtualAdrrAccess) {return std::tuple<int,int>{nextVirtualAdrrAccess, -1};};

    virtual void update(int access) {access++;};

protected:
    RAM::ProcessMemorySpace* pMemSpace;
};


#endif //T2_ALGORITHM_H
