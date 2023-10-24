
#include "RAM.h"

RAM::RAM() {}

RAM::~RAM() {
    
}

void RAM::createProcessMemorySpace(unsigned pid, int virtualMemSize, int pageFrames) {
    RAM::ProcessMemorySpace pMemSpace;
    pMemSpace.pt = new PageTable(pid, virtualMemSize);
    pMemSpace.pages = new Page*[pageFrames];
    for (int i = 0; i < pageFrames; ++i) pMemSpace.pages[i] = nullptr;
    this->memory[pid] = pMemSpace;
}

void RAM::savePage(unsigned pid, int addr, Page* page) {
    this->memory[pid].pages[addr] = page;
}

Page* RAM::getPageFrame(unsigned pid, int addr) {
    if (this->memory[pid].pages[addr] != nullptr) {
        return this->memory[pid].pages[addr];
    }
    return nullptr;
}

RAM::ProcessMemorySpace* RAM::getProcessMemory(unsigned pid) {
    return &this->memory[pid];
}
