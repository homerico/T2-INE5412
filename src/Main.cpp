
#include <iostream>
#include "RAM.h"
#include "FIFO.h"
#include "OPT.h"
#include "LRU.h"

int main (int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Como usar: " << argv[0] << " NUMERO_DE_QUADROS < referencias.txt" << std::endl;
        return 0;
    }

    int num_refs = 0;
    int num_frames = atoi(argv[1]);

    RAM ramFifo(num_frames);
    FIFO fifo(&ramFifo);

    RAM ramLru(num_frames);
    LRU lru(&ramLru);

    RAM ramOpt(num_frames);
    OPT opt(&ramLru);

    char input;
    // FIXME: o último caractere é lido duas vezes
    while (!feof(stdin)) {
        std::cin >> input;
        std::cout << input << std::endl;
        num_refs++;
    }

    std::cout << num_frames << "quadros" << std::endl;
    std::cout << num_refs << "refs" << std::endl;
    std::cout << "FIFO: " << fifo.getPageFaults() << "PFs" << std::endl;
    std::cout << "LRU: " << lru.getPageFaults() << "PFs" << std::endl;
    std::cout << "OPT: " << opt.getPageFaults() << "PFs" << std::endl;

    return 0;
}
