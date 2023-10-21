#include "MMU.h"

MMU::MMU(TLB *tlb) {
    this->tlb = tlb;
}

PageFrame *MMU::getData(int pageNeeded, int processId) {
    return this->tlb->getData(pageNeeded, processId);
}
