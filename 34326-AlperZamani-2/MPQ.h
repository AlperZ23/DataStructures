
#ifndef MPQ_H
#define MPQ_H



typedef int Comparable;

class MPQ {
public:

    MPQ(int maxSize);
    ~MPQ();

    void insert(Comparable val, int tag);
    Comparable Remove(int tag);
    Comparable GetMax();
    bool IsEmpty();

private:
    Comparable *Heap;
    int *Tag;
    int *loc;
    int cap;
    int size;

    void Up(int idx);
    void Down(int idx);
    void Swap(int i, int j);
};

#endif