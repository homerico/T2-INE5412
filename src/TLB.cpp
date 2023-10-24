#include "TLB.h"
#include "OPT.h"
#include "LRU.h"
#include "FIFO.h"

TLB::TLB(int tlbSize) {
    this->tlbSize = tlbSize;
    this->table = new TLBufferEntry[tlbSize];
    /*
    switch (algorithm) {
        case PageReplacementAlgorithm::Algorithm::OPT:
            this->algorithm = new OPT(ram);
            break;
        case PageReplacementAlgorithm::LRU:
            this->algorithm = new LRU(ram);
            break;
        case PageReplacementAlgorithm::FIFO:
            this->algorithm = new FIFO(ram);
            break;
    }
    */
}

int TLB::getTranslation(int virtualAddr, int processId) {
    for (int i = 0; i < this->tlbSize; ++i) {
        if (this->table[i].pid == processId && this->table[i].virtualPage == virtualAddr)
            return table[1].pageFrame; 
    }
    return -1; // -1 significa Page Miss
}
