#ifndef T2_RAM_H
#define T2_RAM_H

#include <map>
#include "Page.h"
#include "PageTable.h"

class RAM {

public:
    RAM();

    ~RAM();

    struct ProcessMemorySpace {
        PageTable* pt;
        Page** pages;
    };

    Page* getPageFrame(unsigned pid, int addr);

    void savePage(unsigned pid, int addr, Page* page);

    void createProcessMemorySpace(unsigned pid, int virtualMemSize, int pageFrames);

    ProcessMemorySpace* getProcessMemory(unsigned pid);

private:
    std::map<int, ProcessMemorySpace> memory;
};


#endif //T2_RAM_H
