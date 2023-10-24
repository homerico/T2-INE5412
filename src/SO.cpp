#include "SO.h"

SO::SO(CPU* cpu, RAM* ram, int processMemorySize, int virtualMemSizePerProcess) {
    this->cpu = cpu;
    this->ram = ram;
    this->processMemorySize = processMemorySize;
    this->virtualMemSizePerProcess = virtualMemSizePerProcess;
    this->pageMissCount = 0;
}

void SO::createProcess(unsigned pid, std::vector<int> entries) {
    // Cria processos com pid gerados sequencialmente
    this->processes[pid] = new Process(pid, entries);
    this->ram->createProcessMemorySpace(pid, this->virtualMemSizePerProcess, this->processMemorySize);
}

int SO::runProcess(unsigned pid) {
    if (this->processes.size() < pid) return -1;

    loadProcess(pid);

    int requestedVirtualPage;
    while(true) {
        requestedVirtualPage = this->cpu->runUntilNextPageAccess();

        if (requestedVirtualPage < 0) break;

        int pageFrame = getAddressFromPageTable(this->activeProcessPid, requestedVirtualPage);
        getPageFromRAM(this->activeProcessPid, pageFrame);
    }
    return 1;
}

int SO::getAddressFromPageTable(unsigned pid, int virtualAddr) {

    RAM::ProcessMemorySpace* pMem = this->ram->getProcessMemory(pid);
    PageTable* pageTable = pMem->pt;
    PageTable::PTEntry* ptEntry = pageTable->getEntry(virtualAddr);
    
    if (!ptEntry->present) {
        // Page Table Miss
        this->pageMissCount++;
        std::tuple<int,int> memTuple = this->prAlgorithim->findMemory(virtualAddr);
        pageTable->removeEntry(std::get<0>(memTuple));
        loadPageFromDiskToMemory(pid, virtualAddr, std::get<1>(memTuple));
        return std::get<1>(memTuple);
    }
    // Page Hit
    this->prAlgorithim->update(virtualAddr);
    return ptEntry->pageFrame;
}

Page* SO::getPageFromRAM(unsigned pid, int pageFrameAddr) {
    return this->ram->getPageFrame(pid, pageFrameAddr);
}

void SO::loadPageFromDiskToMemory(unsigned pid, int virtualAddr, int pageFrame) {
    Page* page = new Page(); //this->disk->getPage(pid, virtualAddr);
    this->ram->savePage(pid, pageFrame, page);
    this->ram->getProcessMemory(pid)->pt->setEntry(virtualAddr, pageFrame);
}

void SO::loadProcess(unsigned pid) {
    this->cpu->setActiveProcess(this->processes[pid]);
    this->activeProcessPid = pid;
    this->pageMissCount = 0;
}

void SO::setPageReplacementAlgorithm(PageReplacementAlgorithm* pr) {
    this->prAlgorithim = pr;
}

int SO::getPageFaults() {
    return this->pageMissCount;
}