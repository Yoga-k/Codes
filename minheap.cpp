/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//Template for representing MinHeap
template <typename T>
class MinHeap {
private:
    vector<T> array;
    int size;
    int capacity;
public:
    //Constructor to set the heap's initial capacity
    MinHeap(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        this->array.resize(capacity);
    }
    //Function to restore heap order at index i
    void heapify(int i)
    {
        int smallest = i;
        
        int left = (2 * i) + 1;
        
        int right = (2 * i) + 2;
        
        if(left < size &&(array[left] < array[smallest]))
        {
            smallest = left;
        }
        if(left < size && (array[right] < array[smallest]))
        {
            smallest = right;
        }
        if(smallest != i)
        {
            swap(array[i], array[smallest]);
            heapify(smallest);
        }
        
    }
    
    //function to create a minheap from a given array
    void buildHeap(const vector<T>& arr)
    {
        capacity = arr.size();
        size = capacity;
        array = arr;
        
        for(int i = (size - 1); i >= 0; i--)
        {
            heapify(i);
        }
    }
    
    void printHeap() const {
        for(int i = 0; i < size; ++i)
        {
            cout<<array[i] <<" ";
        }
        cout<<endl;
    }
    
};

int main()
{
    //create a object name MinHeap object named minHeap
    MinHeap<int> minHeap(6);
    vector<int> arr = {15, 10, 5, 4, 3, 2};
    
    minHeap.buildHeap(arr);
    //print the min heap
    minHeap.printHeap();
    // cout<<"Min Heap built from the array: ";

    return 0;
}