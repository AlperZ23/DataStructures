
#include "MPQ.h"

MPQ::MPQ(int maxSize)
{
    cap = maxSize;
    size = 0;
    Heap = new Comparable[cap + 1];
    Tag = new int[cap + 1];
    loc = new int[cap + 1];

    int i;
    
    for (i = 0; i <= cap; i++) {
        loc[i] = 0;
    }
}

MPQ::~MPQ()
{
    
    delete[] Heap;
    delete[] Tag;
    delete[] loc;
    
}

bool MPQ::IsEmpty()
{
    
    return size == 0;
}

Comparable MPQ::GetMax()
{
    if (size == 0) {
        return 0;
    }
    return Heap[1];
}

void MPQ::Swap(int i, int j)
{
    Comparable tempValue = Heap[i];
    int temptag = Tag[i];

    Heap[i] = Heap[j];
    Tag[i] = Tag[j];

    Heap[j] = tempValue;
    Tag[j] = temptag;

    loc[Tag[i]] = i;
    loc[Tag[j]] = j;
}

void MPQ::Up(int idx)
{
    
    int curr = idx;
    
    while (curr > 1) {
        int last = curr / 2;
        if (Heap[curr] > Heap[last]) {
            Swap(curr, last);
            curr = last;
        } else {
            break;
        }
    }
}

void MPQ::Down(int idx)
{
    int curr = idx;

    while (true) {

        int left = curr * 2;
        int right = left + 1;
        int largest = curr;

        if (left <= size && Heap[left] > Heap[largest]) {
            largest = left;
        }
        if (right <= size && Heap[right] > Heap[largest]) {
            largest = right;
        }

        if (largest != curr) {
            Swap(curr, largest);
            curr = largest;
        } else {
            break;
        }
    }
}

void MPQ::insert(Comparable val, int tag)
{
    if (tag < 0 || tag > cap) {
        return;
    }
    if (size == cap) {
        return;
    }

    size = size + 1;
    int idx= size;

    Heap[idx] = val;
    Tag[idx] = tag;
    loc[tag] = idx;

    Up(idx);
}

Comparable MPQ::Remove(int tag)
{
    if (tag < 0 || tag > cap) {
        return 0;
    }
    int idx = loc[tag];
    if (idx == 0 || size == 0) {
        return 0;
    }

    Comparable removed_val = Heap[idx];

    if (idx == size) {
        size = size - 1;
        loc[tag] = 0;
        return removed_val;
    }

    Heap[idx] = Heap[size];
    Tag[idx] = Tag[size];
    loc[Tag[idx]] = idx;

    size = size - 1;
    loc[tag] = 0;

    if (idx > 1 && Heap[idx] > Heap[idx / 2]) {
        Up(idx);
    } else {
        Down(idx);
    }

    return removed_val;
}
