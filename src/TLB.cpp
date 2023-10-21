#include "TLB.h"
#include "OPT.h"
#include "LRU.h"
#include "FIFO.h"

TLB::TLB(RAM *ram, PageReplacementAlgorithm::Algorithm algorithm) {
    this->ram = ram;
    this->pageFaults = 0;
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
}

int TLB::getPageFaults() {
    return this->pageFaults;
}

PageFrame *TLB::getData(int pageNeeded, int processId) {
    PageFrame *pageFrame = this->ram->getPageFrame(pageNeeded);
    // Se for nullptr, significa que houve um miss na TLB
    if (pageFrame == nullptr) {
        this->pageFaults++;
        this->algorithm->replacePage(pageNeeded, processId);
        pageFrame = this->ram->getPageFrame(pageNeeded);
    }
    return pageFrame;
}
