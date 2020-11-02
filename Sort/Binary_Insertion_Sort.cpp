// Idea:
//  - In the insertion sort algorithm, finding the insert position is sequential.For a
//    better way, we use the binary search method to find this position.
//
//
// Steps :
//    - S1 : i = 1; (a[0] sorted because there is only 1 element).
//    - S2: x = a[i];
//    - S3: Find position pos to insert x into the array from a[0] to a[i - 1] by binary search
//    - S4: Move the elements from a[pos] to a[i - 1] to the right by 1 position to
//           accommodate the insertion of x in this pos position.
//    - S5: a[pos] = x;
//    - S6: i = i + 1; If i < n, go to S2.
//                      Otherwise, go to end.




#include <iostream>
using namespace std;



int binarySearch(int a[], int k, int x)
{
    int mid;
    int left = 0, right = k;
    do {
        mid = (left + right) / 2;
        if (x <= a[mid]) right = mid - 1;
        else left = mid + 1;
    } while (left <= right);
    if (x > a[mid]) return mid + 1;
    return mid;
}


void BinaryInserion_Sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int pos = binarySearch(a, i -1, x);
        for (int j = i; j > pos; j--)
            a[j] = a[j - 1];
        a[pos] = x;
    }
}



int main()
{
    int a[] = { 2,1,6, 2, 9, 11, 3, 4,3,5 };
    for (int i = 0; i < 10; i++)
        cout << a[i] << "  ";
    cout << endl;


    BinaryInserion_Sort(a, 10);

    for (int i = 0; i < 10; i++)
        cout << a[i] << "  ";
}