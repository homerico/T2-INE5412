#ifndef T2_INE5412_CPU_H
#define T2_INE5412_CPU_H

#include <string>
#include <vector>
#include "MMU.h"
#include "Process.h"

class CPU {
public:
    CPU(MMU *mmu, std::vector<int> entries, int id);

    void run();

private:
    int id;
    MMU *mmu;
    Process *process;
};


#endif //T2_INE5412_CPU_H
