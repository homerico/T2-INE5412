#include <iostream>
#include <string>
#include "RAM.h"
#include "CPU.h"

int main (int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Como usar: " << argv[0] << " NUMERO_DE_QUADROS < referencias.txt" << std::endl;
        return 0;
    }

    int ReferencesNum = 0;
    int phisicalPagesNum = atoi(argv[1]);

    std::vector<int> entries;
    // Substitui o !feof(stdin), que estava causando problemas ao ler o último input duas vezes
    for (std::string input; std::cin >> input; ) {
        int tmp = stoi(input);
        entries.push_back(tmp);
        ReferencesNum++;
    }

    RAM ramFifo(phisicalPagesNum);
    TLB tlbFifo(&ramFifo, PageReplacementAlgorithm::Algorithm::FIFO);
    MMU mmuFifo(&tlbFifo);
    CPU cpuFifo(&mmuFifo, entries, 1);

    RAM ramLru(phisicalPagesNum);
    TLB tlbLru(&ramLru, PageReplacementAlgorithm::Algorithm::LRU);
    MMU mmuLru(&tlbLru);
    CPU cpuLru(&mmuLru, entries, 2);

    RAM ramOpt(phisicalPagesNum);
    TLB tlbOpt(&ramOpt, PageReplacementAlgorithm::Algorithm::OPT);
    MMU mmuOpt(&tlbOpt);
    CPU cpuOpt(&mmuOpt, entries, 3);

    cpuFifo.run();
    cpuLru.run();
    cpuOpt.run();

    std::cout << phisicalPagesNum << " quadros" << std::endl;
    std::cout << ReferencesNum << " refs" << std::endl;
    std::cout << "FIFO: " << tlbFifo.getPageFaults() << " PFs" << std::endl;
    std::cout << "LRU: " << tlbLru.getPageFaults() << " PFs" << std::endl;
    std::cout << "OPT: " << tlbOpt.getPageFaults() << " PFs" << std::endl;

    return 0;
}
