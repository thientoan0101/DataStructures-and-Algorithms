// Idea:
//  - Partition the original array into two sub arrays.Repeat partitioning on
//    the sub array until the array has 1 element. (top - down)
//  - Merge each pair of sub arrays into an array in order and repeat for its
//    two parent arrays, until the original array size is reached. (bottom - up)
//
// Steps :
//    - S1 : mid = (l + r) / 2;
//    - S2: Split array a into 2 subarrays b, c
//    - S3 : If the subarray b, c has more than 2 elements, then repeat S2.
//    - S4 : Merge two child arrays to get an ordered parent array.
//              Repeat until the array is full of elements

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



void merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int i = 0; i < n2; i++)
		R[i] = a[m + 1 + i];
	int i = 0, j = 0;

	for (int k = l; k <= r; k++)             
	{
		if (i < n1 && (j >= n2 || L[i] < R[j]))
		{
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
	}
	delete[] L;
	delete[] R;
}

void MergeSort(int a[], int l, int r)
{
	if (l >= r)  return;
	int mid = l + (r - l) / 2;
	MergeSort(a, l, mid);
	MergeSort(a, mid + 1, r);
	merge(a, l, mid, r);
}



int main()
{
    int a[] = { 7,3,9,10,1,5,2,4,8 };
    
    for (int i = 0; i < 9; i++)
        cout << a[i] << "  ";
    cout << endl;


    mergeSort(a, 0, 8);

    for (int i = 0; i < 9; i++)
        cout << a[i] << "  ";
}