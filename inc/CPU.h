#ifndef T2_INE5412_CPU_H
#define T2_INE5412_CPU_H

#include <string>
#include <vector>
#include <tuple>
#include "MMU.h"
#include "Process.h"

class CPU {
public:
    CPU(MMU *mmu);

    void setActiveProcess(Process* process);

    /* enum EXIT_CODE {NO_ACTIVE_PROCESS, PROCESS_TERMINATED, TLB_HIT, TLB_MISS}; */

    int runUntilNextPageAccess();

private:
    MMU *mmu;
    Process *activeProcess;
};


#endif //T2_INE5412_CPU_H
