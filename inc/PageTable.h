#ifndef T2_PAGE_TABLE_H
#define T2_PAGE_TABLE_H

class PageTable {
public:

    PageTable(int pid, int size);

    ~PageTable() = default;

    struct PTEntry {
        bool present;
        bool modified;
        int pageFrame;
    };

    enum ENTRY_STATUS {PT_MISS = -1, PT_HIT = 1};

    PTEntry* getEntry(int virtualAddr);

    void setEntry(int virtualAddr, int pageFrame);

    void removeEntry(int virtualAddr);

    void setEntryModified(int virtualAddr);

    bool getEntryModified(int virtualAddr);

private:
    int pid;
    PTEntry* table;
};

#endif //T2_PAGE_TABLE_H