#ifndef T2_SO_H
#define T2_SO_H

#include <map>
#include <tuple>
#include "CPU.h"
#include "RAM.h"
#include "Process.h"
#include "PageTable.h"
#include "PageReplacementAlgorithm.h"

class SO {
public:
    SO(CPU* cpu, RAM* ram, int processMemorySize, int virtualMemSizePerProcess);

    ~SO() = default;

    void createProcess(unsigned pid, std::vector<int> entries);

    int runProcess(unsigned pid);

    void loadProcess(unsigned pid);

    Page* getPageFromRAM(unsigned pid, int pageFrameAddr);

    int getAddressFromPageTable(unsigned pid, int virtualAddr);

    void loadPageFromDiskToMemory(unsigned pid, int virtualAddr, int pageFrame);

    void setPageReplacementAlgorithm(PageReplacementAlgorithm* pr);

    int getPageFaults();

private:
    CPU* cpu;
    RAM* ram;
    int processMemorySize;
    int virtualMemSizePerProcess;
    int activeProcessPid;
    
    std::map<int, Process*> processes;

    PageReplacementAlgorithm* prAlgorithim;

    int pageMissCount;
};

#endif //T2_SO_H
