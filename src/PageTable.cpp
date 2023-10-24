#include "PageTable.h"

PageTable::PageTable(int pid, int size) {
    this->pid = pid;
    this->table = new PTEntry[size];
    for (int i = 0; i < size; ++i) {
        this->table[i].present = false;
        this->table[i].modified = false;
        this->table[i].pageFrame = -1;
    }
}

PageTable::PTEntry* PageTable::getEntry(int virtualAddr) {
    return &this->table[virtualAddr];
}

void PageTable::setEntry(int virtualAddr, int pageFrame) {
    PageTable::PTEntry entry;
    entry.present = true;
    entry.modified = false;
    entry. pageFrame = pageFrame;
    this->table[virtualAddr] = entry;
}

void PageTable::removeEntry(int virtualAddr) {
    PageTable::PTEntry entry;
    entry.present = false;
    entry.modified = false;
    entry. pageFrame = -1;
    this->table[virtualAddr] = entry;
}

void PageTable::setEntryModified(int virtualAddr) {
    this->table[virtualAddr].modified = true;
}

bool PageTable::getEntryModified(int virtualAddr) {
    return this->table[virtualAddr].modified;
}

