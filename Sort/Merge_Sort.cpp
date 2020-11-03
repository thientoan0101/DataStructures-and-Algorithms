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

void merge(int a[], int l, int mid, int r, int temp[])
{
    int ileft = l, iRight = mid+1;              // bien chay cho 2 mang con
    for (int j = l; j <= r; j++)             // bien chay cho temp[]
    {
        if (ileft <= mid && (iRight > r || a[ileft] < a[iRight]))
        {
            temp[j] = a[ileft];
            ileft++;
        }
        else {
            temp[j] = a[iRight];
            iRight++;
        }
    }
}

void copyArr(int temp[], int l, int r, int a[])
{
    for (int i = l; i <= r; i++)
    {
        a[i] = temp[i];
    }
}
void mergeSort(int a[], int l, int r, int temp[])
{
    if (l>=r)  return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid, temp);
    mergeSort(a, mid+1, r, temp);
    merge(a, l, mid, r, temp);
    copyArr(temp, l, r, a);
}


int main()
{
    int a[] = { 7,3,9,10,1,5,2,4,8 };
    int temp[9];
    for (int i = 0; i < 9; i++)
        cout << a[i] << "  ";
    cout << endl;


    mergeSort(a, 0, 8, temp);

    for (int i = 0; i < 9; i++)
        cout << a[i] << "  ";
}