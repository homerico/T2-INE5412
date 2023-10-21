#include "CPU.h"

CPU::CPU(MMU *mmu, std::vector<int> entries, int id) {
    this->id = id;
    this->mmu = mmu;
    this->process = new Process(1, entries);
}

void CPU::run() {
    while (this->process->run() != 0) {
        PageFrame *pageFrame = this->mmu->getData(this->process->getActualPageNeeded(), this->process->getId());
        this->process->setActualPageFrame(pageFrame);
    }
}
