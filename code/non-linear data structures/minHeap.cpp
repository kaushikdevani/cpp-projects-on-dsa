#include<iostream>
#include <math.h>

using namespace std;

class MinHeap 
{
    public:
        int * harr; // pointer to array of elements in heap
        int capacity; // maximum possible size of min heap
        int heap_size; // Current number of elements in min heap

        MinHeap(int cap)
        {
            heap_size = 0;
            capacity = cap;
            harr= new int[cap];
        }
};