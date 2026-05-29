
#include <iostream>
#include <fstream>
#include "MPQ.h"

using namespace std;


void swap(int *x, int *tag, int *side, int i, int j)
{
    int tempx = x[i];
    x[i] = x[j];
    x[j] = tempx;

    int temptag = tag[i];
    tag[i] = tag[j];
    tag[j] = temptag;

    int tempside = side[i];
    side[i] = side[j];
    side[j] = tempside;
}


void heapsortmap(int *x, int *tag, int *side, int n, int i)
{
    int largest = i;
    while (true) {
        int left = 2 * largest + 1;
        int right = left + 1;
        int next = largest;

        if (left < n && x[left] > x[next]) {
            next = left;
        }
        if (right < n && x[right] > x[next]) {
            next = right;
        }

        if (next != largest) {
            swap(x, tag, side, largest, next);
            largest = next;
        } else {
            break;
        }
    }
}

void heapSort(int *x, int *tag, int *side, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapsortmap(x, tag, side, n, i);
    }

    for (i = n - 1; i > 0; i--) {
        swap(x, tag, side, 0, i);
        heapsortmap(x, tag, side, i, 0);
    }
}

int main()
{
    ifstream inFile("input.txt");
    if (!inFile) {
        return 1;
    }

    int n;
    inFile >> n;
    if (!inFile) {
        return 1;
    }

    int *leftX = new int[n + 1];
    int *height = new int[n + 1];
    int *rightX = new int[n + 1];

    int i;
    for (i = 1; i <= n; i++) {

        inFile >> leftX[i];
        inFile >> height[i];
        inFile >> rightX[i];

        if (!inFile) {
            delete[] leftX;
            delete[] height;
            delete[] rightX;
            return 1;
        }
    }

    inFile.close();

    int count = 2 * n;
    int *x = new int[count];
    int *tag = new int[count];
    int *side = new int[count];

    int idx = 0;
    for (i = 1; i <= n; i++) {
        x[idx] = leftX[i];
        tag[idx] = i;
        side[idx] = 0;
        idx = idx + 1;

        x[idx] = rightX[i];
        tag[idx] = i;
        side[idx] = 1;
        idx = idx + 1;
    }

    heapSort(x, tag, side, count);

    MPQ mpq(n);

    cout << 0 << " " << 0 << endl;

    int currentHeight = 0;
    int pos = 0;
    while (pos < count) {
        int currentX = x[pos];

        while (pos < count && x[pos] == currentX) {
            int b = tag[pos];
            if (side[pos] == 0) {
                mpq.insert(height[b], b);
            } else {
                mpq.Remove(b);
            }
            pos = pos + 1;
        }

        int newHeight;
        if (mpq.IsEmpty()) {
            newHeight = 0;
        } else {
            newHeight = mpq.GetMax();
        }

        if (newHeight != currentHeight) {
            cout << currentX << " " << newHeight << endl;
            currentHeight = newHeight;
        }
    }

    delete[] leftX;
    delete[] height;
    delete[] rightX;
    delete[] x;
    delete[] tag;
    delete[] side;

    return 0;
}
