#include "CPU.h"

CPU::CPU(MMU *mmu) {
    this->mmu = mmu;
    this->activeProcess = nullptr;
}

void CPU::setActiveProcess(Process* process) {
    this->activeProcess = process;
}

int CPU::runUntilNextPageAccess() {

    if (this->activeProcess == nullptr) return -2;

    int requestedPage = this->activeProcess->runUntilNextPageAccess();

    if (requestedPage < 0) {
        // O processo terminou
        return -1;
    }

   return requestedPage;
}
