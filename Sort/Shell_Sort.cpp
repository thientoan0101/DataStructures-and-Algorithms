// Idea:
//  - Divide the original array into sub arrays of elements h positions apart.
//  - Sorts elements in sub arrays.
//  - Reduce the distance h to form a new sub array.Stop when h = 1
//
//
// Steps :
//    - S1 : Initialize shell size h0, h1, �, hk - 1 such that hi > hi + 1 and hk - 1 = 1;
//    - S2: i = 0;
//    - S3: Divide the original array into sub arrays with h[i] spacing.Sort each subarray using the insertion sort.
//    - S4 : i = i + 1; If i < k, go to S2.
//                      Otherwise, go to end.




#include <iostream>
using namespace std;



void shellSort(int a[], int n)
{
    int h[10] = {100,75, 50, 25, 10, 5, 4, 3, 2, 1};
    
    for (int step = 0; step<10;step++)
    {
        int len = h[step];
        for (int i = len; i < n; i = i++)
        {
            int x = a[i];
            int pos = i - len;
            while (pos >= 0 && a[pos] > x)
            {
                a[pos + len] = a[pos];
                pos = pos - len;
            }
            a[pos + len] = x;
        }
    }
}



int main()
{
    int a[] = {35,33,42,10,14,19,27,44,35,33,42,10,14,19,27,44 };
    for (int i = 0; i < 16; i++)
        cout << a[i] << "  ";
    cout << endl;


    shellSort(a, 16);

    for (int i = 0; i < 16; i++)
        cout << a[i] << "  ";
}