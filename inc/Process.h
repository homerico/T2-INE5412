#ifndef T2_INE5412_PROCESS_H
#define T2_INE5412_PROCESS_H

#include <vector>
#include "PageFrame.h"

class Process {
public:
    Process(int id, std::vector<int> entries);

    int run();

    int getActualPageNeeded();

    int getId();

    void setActualPageFrame(PageFrame *pFrame);

private:
    int id;
    int actualPageNeeded;
    std::vector<int> entries;
    PageFrame *actualPageFrame;

    void consumePageFrame();
};


#endif //T2_INE5412_PROCESS_H
