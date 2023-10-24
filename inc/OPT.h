#ifndef T2_OPT_H
#define T2_OPT_H

#include <vector>
#include <map>
#include "PageReplacementAlgorithm.h"

class OPT : public PageReplacementAlgorithm {

public:
    OPT(unsigned accessListMaxSize, std::vector<int> entries);

    ~OPT() = default;

    std::tuple<int,int> findMemory(int nextVirtualAdrrAccess);

    void update(int virtualAddr);

private:
    int location;
    unsigned accessListMaxSize;
    std::vector<int> entries;
    std::map<int,int> memTranslate;
    std::map<int,int> tags;
};


#endif //T2_OPT_H
