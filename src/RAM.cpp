
#include "RAM.h"

RAM::RAM(int frames) {
    this->pageFrames = std::vector<PageFrame *>(frames);
    for (int i = 0; i < frames; i++) {
        this->pageFrames[i] = new PageFrame();
    }
}

RAM::~RAM() {
    for (auto &pageFrame: this->pageFrames) {
        delete pageFrame;
    }
    this->pageFrames.clear();
}

PageFrame *RAM::getPageFrame(int refPageNeeded) {
    for (auto &pageFrame : this->pageFrames) {
        if (pageFrame->getRef() == refPageNeeded) {
            return pageFrame;
        }
    }
    return nullptr;
}
