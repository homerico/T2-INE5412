#include "OPT.h"

OPT::OPT(unsigned accessListMaxSize, std::vector<int> entries) : PageReplacementAlgorithm() {
    this->location = 0;
    this->accessListMaxSize = accessListMaxSize;
    this->entries = entries;
}

std::tuple<int,int> OPT::findMemory(int nextVirtualAdrrAccess) {
    if (this->memTranslate.size() < this->accessListMaxSize) {

        this->memTranslate[nextVirtualAdrrAccess] = this->memTranslate.size();

        location++;
        std::map<int,int>::iterator it;
        for (it = this->tags.begin(); it != this->tags.end(); ++it) it->second--;

        int nextOccurrance = 0;
        for (unsigned i = location; i < this->entries.size(); ++i) {
            if (this->entries.at(i) == nextVirtualAdrrAccess) {
                nextOccurrance = i - location;
                break;
            }
        }
        this->tags[nextVirtualAdrrAccess] = nextOccurrance;

        return std::tuple<int,int>{-1, this->memTranslate.size()};
    }

    int biggestTag = -1; int who;
    std::map<int,int>::iterator it;
    for (it = this->tags.begin(); it != this->tags.end(); ++it) {
        if (it->second > biggestTag) {
            biggestTag = it->second;
            who = it->first;
        }
    }

    int pageFrame = this->memTranslate[who];
    this->memTranslate.erase(who);
    this->tags.erase(who);
    this->memTranslate[nextVirtualAdrrAccess] = pageFrame;

    location++;
    for (it = this->tags.begin(); it != this->tags.end(); ++it) it->second--;

    int nextOccurrance = 0;
    for (unsigned i = location; i < this->entries.size(); ++i) {
        if (this->entries.at(i) == nextVirtualAdrrAccess) {
            nextOccurrance = i - location;
            break;
        }
    }
    this->tags[nextVirtualAdrrAccess] = nextOccurrance;

    return std::tuple<int,int>{who,pageFrame};
}

void OPT::update(int virtualAddr) {
    this->location++;
    std::map<int,int>::iterator it;
    for (it = this->tags.begin(); it != this->tags.end(); ++it) it->second--;
    int nextOccurrance = 0;
    for (unsigned i = location; i < this->entries.size(); ++i) {
        if (this->entries.at(i) == virtualAddr) {
            nextOccurrance = i - location;
            break;
        }
    }
    this->tags[virtualAddr] = nextOccurrance;
}