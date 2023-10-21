#include "LRU.h"

LRU::LRU(RAM *ram) : PageReplacementAlgorithm() {
    this->ram = ram;
}
