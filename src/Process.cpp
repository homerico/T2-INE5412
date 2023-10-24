#include "Process.h"

Process::Process(int pid, std::vector<int> entries) {
    this->pid = pid;
    this->entries = entries;
}

int Process::runUntilNextPageAccess() {
    executeCode();
    if (entries.size() > 0) {
        int calledPage = entries[0];
        entries.erase(entries.begin());
        // retorna o endereco virtual da pagina requisitada
        return calledPage;
    }
    // retorna -1 se não há mais pedidos de acesso a páginas
    return -1;
}

int Process::getPid() {
    return this->pid;
}

void Process::executeCode(){
    // Vazio, usado apenas como simulação
}
