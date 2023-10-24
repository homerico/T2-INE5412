#include <iostream>
#include <string>
#include <math.h>
#include "RAM.h"
#include "CPU.h"
#include "SO.h"
#include "FIFO.h"
#include "LRU.h"

int main (int argc, char* argv[]) {

    /* Leitura do Input*/

    if (argc < 2) {
        std::cout << "Como usar: " << argv[0] << " NUMERO_DE_QUADROS < referencias.txt" << std::endl;
        return 0;
    }

    int ReferencesNum = 0;
    int pageFramesPerProcess = atoi(argv[1]);
    int virtualMemSizePerProcess = 32768;

    std::vector<int> entries;
    // Substitui o !feof(stdin), que estava causando problemas ao ler o último input duas vezes
    for (std::string input; std::cin >> input; ) {
        int tmp = stoi(input);
        entries.push_back(tmp);
        ReferencesNum++;
    }

    /* Setup Computer */

    int tlbSize = int(floor(sqrt(pageFramesPerProcess)));

    RAM* ram = new RAM();
    TLB tlb(tlbSize);
    MMU mmu(&tlb);
    CPU cpu(&mmu);
    SO so(&cpu, ram, pageFramesPerProcess, virtualMemSizePerProcess);

    /* Run Algorithms */

    std::vector<int> fifoEntries(entries);
    so.setPageReplacementAlgorithm(new FIFO(pageFramesPerProcess));
    so.createProcess(fifoEntries);
    so.runProcess(0);
    int fifoFaults = so.getPageFaults();

    std::vector<int> lruEntries(entries);
    so.setPageReplacementAlgorithm(new LRU(pageFramesPerProcess));
    so.createProcess(lruEntries);
    so.runProcess(1);
    int lruFaults = so.getPageFaults();
/*
    so.setPageReplacementAlgorithm(new OPT(pageFramesPerProcess, entries));
    so.createProcess(entries);
    so.loadProcess(2);
    so.runProcess(2);
*/
/*
    cpuFifo.run();
    cpuLru.run();
    cpuOpt.run();
*/

    std::cout << pageFramesPerProcess << " quadros" << std::endl;
    std::cout << ReferencesNum << " refs" << std::endl;
    std::cout << "FIFO: " << fifoFaults << " PFs" << std::endl;
    std::cout << "LRU: " << lruFaults << " PFs" << std::endl;
    //std::cout << "OPT: " << tlbOpt.getPageFaults() << " PFs" << std::endl;

    return 0;
}
