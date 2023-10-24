#ifndef T2_INE5412_PROCESS_H
#define T2_INE5412_PROCESS_H

#include <vector>
#include "Page.h"

class Process {
public:
    Process(int pid, std::vector<int> entries);

    // retorna o endereco virtual da pagina requisitada
    int runUntilNextPageAccess();

    int getPid();

private:
    int pid;
    std::vector<int> entries;
    void executeCode();
};


#endif //T2_INE5412_PROCESS_H
