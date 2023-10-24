#ifndef T2_PAGE_H
#define T2_PAGE_H


class Page {
public:
    Page();

    ~Page() = default;

    int getRef();

private:
    int page;
    int lastUsed;
};


#endif //T2_PAGE_H
