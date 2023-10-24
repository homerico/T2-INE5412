#include "CPU.h"

CPU::CPU(MMU *mmu) {
    this->mmu = mmu;
    this->activeProcess = nullptr;
}

void CPU::setActiveProcess(Process* process) {
    this->activeProcess = process;
}

int CPU::runUntilNextPageAccess() {

    if (this->activeProcess == nullptr) return -2;

    int requestedPage = this->activeProcess->runUntilNextPageAccess();

    if (requestedPage < 0) {
        // O processo terminou
        return -1;
    }

    /*
    // verifica se o endereco da pagina existe na TLB
    int addr = this->mmu->retreivePhysicalAddress(this->activeProcess->getPid(), requestedPage);

    if (addr < 0) {
        // TLB Miss, retorna o endereco virtual da pagina requisitada para o SO procurar na Tabela de Paginas
        return std::tuple<CPU::EXIT_CODE,int>{CPU::EXIT_CODE::TLB_MISS,requestedPage};
    }
    // else: TLB Hit, retorna o endereco fisico da moldura de pagina
    return std::tuple<CPU::EXIT_CODE,int>{CPU::EXIT_CODE::TLB_HIT,addr};
    */

   return requestedPage;
}
