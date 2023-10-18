#include "FIFO.h"


FIFO::FIFO(RAM *ram) : PageReplacementAlgorithm() {
    this->ram = ram;
}

int FIFO::getPageFaults() {
    return pageFaults;
}
