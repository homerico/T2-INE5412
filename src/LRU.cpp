#include "LRU.h"

LRU::LRU(unsigned accessListMaxSize) : PageReplacementAlgorithm() {
    this->accessListMaxSize = accessListMaxSize;
}

std::tuple<int,int> LRU::findMemory(int nextVirtualAddrAccess) {
    if(this->accessList.size() < this->accessListMaxSize) {
        this->accessList.push_front(nextVirtualAddrAccess);
        this->memTranslate[nextVirtualAddrAccess] = this->accessList.size();
        return std::tuple<int,int>{-1, this->accessList.size()};
    }
    int last = this->accessList.back();
    this->accessList.pop_back();
    this->accessList.push_front(nextVirtualAddrAccess);
    this->memTranslate[nextVirtualAddrAccess] = this->memTranslate[last];
    this->memTranslate.erase(last);
    return std::tuple<int,int>{last,this->memTranslate[nextVirtualAddrAccess]};
}

void LRU::update(int virtualMemAccess) {
    this->accessList.remove(virtualMemAccess);
    this->accessList.push_front(virtualMemAccess);
}
