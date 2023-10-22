#include "MMU.h"

MMU::MMU(TLB *tlb) {
    this->tlb = tlb;
}

PageFrame *MMU::getData(int pageNeeded, int processId) {
    PageFrame *pageFrame = this->tlb->getData(pageNeeded, processId);
    if (pageFrame == nullptr) {
        // TODO: implementar page table
        pageFrame = this->pageTable->getData(pageNeeded, processId);
        if (pageFrame == nullptr) {
            // TODO: implementar SO que possui referência da RAM e do disco, inclusive implementar disco tbm
            //  - Após um page fault (falha de página) ocorrer, o sistema operacional é responsável por chamar o
            //      algoritmo de substituição de páginas para decidir qual página deve ser retirada da memória RAM
            //      para dar espaço à página que causou o page fault
            // - O SO deve armazenar a quantidade de page faults que ocorreram
            // manda pro SO fazer swap do disco para a RAM e o SO deve atualizar a Page Table
            this->SO->swap(pageNeeded, processId);
        }
        pageFrame = this->pageTable->getData(pageNeeded, processId);
        // A MMU que deve atualizar a TLB
        this->tlb->update(pageNeeded, processId, pageFrame);
    }
    return this->tlb->getData(pageNeeded, processId);
}
