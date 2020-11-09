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

void heapify(int a[], int parentIndex, int lastIndex)
{
	int left = parentIndex * 2 + 1;
	int right = parentIndex * 2 + 2;
	int biggest = parentIndex;

	if (left < lastIndex && a[left] > a[biggest])
		biggest = left;
	if (right < lastIndex && a[right] > a[biggest])
		biggest = right;
	if (biggest != parentIndex)
	{
		swap(a[biggest], a[parentIndex]);
		heapify(a, biggest, lastIndex);
	}

}

void HeapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, i, n - 1);
	}

	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, 0, i);
	}
}



int main()
{
    int a[] = { 5,7,1,8,6,9,4,2,3};
    for (int i = 0; i < 9; i++)
        cout << a[i] << "  ";
    cout << endl;


    heapSort(a, 9);

    for (int i = 0; i < 9; i++)
        cout << a[i] << "  ";
}