#include "OPT.h"

OPT::OPT(RAM *ram) : PageReplacementAlgorithm() {
    this->ram = ram;
}

int OPT::getPageFaults() {
    return pageFaults;
}
