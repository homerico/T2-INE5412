#include "FIFO.h"


FIFO::FIFO(unsigned accessListMaxSize) : PageReplacementAlgorithm() {
    this->accessListMaxSize = accessListMaxSize;
}

std::tuple<int,int> FIFO::findMemory(int nextVirtualAddrAccess) {
    if (this->accessList.size() < this->accessListMaxSize) {
        this->accessList.push(std::tuple<int,int>{nextVirtualAddrAccess,this->accessList.size()});
        return std::tuple<int,int>{-1, this->accessList.size()};
    }
    else {
        std::tuple<int,int> exchange = this->accessList.front();
        this->accessList.pop();
        this->accessList.push(std::tuple<int,int>{nextVirtualAddrAccess, std::get<1>(exchange)});
        return exchange;
    }
}

void FIFO::update(int useless) {useless++;}