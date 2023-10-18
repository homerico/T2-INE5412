#include "LRU.h"

LRU::LRU(RAM *ram) : PageReplacementAlgorithm() {
    this->ram = ram;
}

int LRU::getPageFaults() {
    return pageFaults;
}
