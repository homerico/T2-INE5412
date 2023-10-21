#ifndef T2_PAGEFRAME_H
#define T2_PAGEFRAME_H


class PageFrame {
public:
    PageFrame();

    ~PageFrame() = default;

    int getRef();

private:
    int page;
    int lastUsed;
};


#endif //T2_PAGEFRAME_H
