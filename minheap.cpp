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
    
}

int main()
{
    std::cout<<"Hello World";
    MinHeap<int> minHeap(6);
    vector<int> arr = {15, 10, 5, 4, 3, 2};
    
    //Build the heap fromt he std::array<T, N> ;
    minHeap.buildHeap(arr);
    
    //print the min heap
    cout<<"Min Heap built from the array: ";
   // minHeap.print

    return 0;
}