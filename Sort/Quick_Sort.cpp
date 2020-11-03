// Algorithm: consists of 2 phases
//  - Phase 1 : Modify the original array to the heap.
//  - Phase 2 : Sort arrays based on heap.
//      + S1 : Swap the largest element and the last element in array;
//      + S2: Removes the last element from the heap, modifying the rest to
//             the heap.
//      + S3 : If the heap has an element, then repeat S1.
//             Otherwise, go to end.



#include <iostream>
#include <algorithm>
using namespace std;



void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void quickSort(int a[], int left, int right)
{
    int i = left, j = right;
    int pivot = a[right];

    while (i <= j)
    {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;    j--;
        }
    }
    if (left < j) quickSort(a, left, j);
    if (right > i) quickSort(a, i, right);
}

int main()
{
    int a[] = { 3,7,1,8,5,4,6};
    for (int i = 0; i < 7; i++)
        cout << a[i] << "  ";
    cout << endl;


    quickSort(a, 0, 6);

    for (int i = 0; i < 7; i++)
        cout << a[i] << "  ";
}