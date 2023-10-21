#include "Process.h"

Process::Process(int id, std::vector<int> entries) {
    this->id = id;
    this->entries = entries;
    this->actualPageNeeded = 0;
    this->actualPageFrame = nullptr;
}

int Process::run() {
    consumePageFrame();
    if (entries.size() > 0) {
        this->actualPageNeeded = entries[0];
        entries.erase(entries.begin());
        // retorna 1 para indicar que há pedido de acesso a uma página física
        return 1;
    }
    // retorna 0 se não há mais pedidos de acesso a páginas físicas
    return 0;
}

int Process::getActualPageNeeded() {
    return this->actualPageNeeded;
}

int Process::getId() {
    return this->id;
}

void Process::setActualPageFrame(PageFrame *pFrame) {
    this->actualPageFrame = pFrame;
}

void Process::consumePageFrame(){
    // Vazio, usado apenas como simulação
}
