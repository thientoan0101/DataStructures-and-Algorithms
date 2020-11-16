//PROBLEM: Given an array of integers (both odd and even),
//         sort them in such a way that the first part of the array contains odd numbers sorted in descending order, rest portion contains even numbers sorted in ascending order.
//
//Examples: 
//Input  : arr[] = {1, 2, 3, 5, 4, 7, 10}
//Output : arr[] = {7, 5, 3, 1, 2, 4, 10}
//
//Input  : arr[] = {0, 4, 5, 3, 7, 2, 1}
//Output : arr[] = {7, 5, 3, 1, 0, 2, 4} 

#include <iostream>
#include <algorithm>
using namespace  std;

// Method 2:

void twoWaySort2(int arr[], int n) 
{ 
    // Make all odd numbers negative 
    for (int i = 0; i < n; i++) 
        if (arr[i]%2!=0) // Check for odd 
            arr[i] = -arr[i]; 
  
    // Sort all numbers 
    sort(arr, arr + n); 
  
    // Retaining original array 
    for (int i = 0; i < n; i++) 
        if (arr[i] & 1) 
            arr[i] *= -1; 
}
void twoWaySort(int a[], int n)
{
    int l = 0, r = n-1;
    int k = 0;  // count odd number.

    // Partition the input array such that all odd elements are moved to left and all even elements on right. 
    while (l<=r)
    {
        // find the first even number from left side:
        while (a[l]%2!=0)
        {
            l++;
            k++;
        }
        // find the fisrt odd number fromt right side:
        while (l<=r && a[r]%2==0)
        {
            r--;
        }
        if (l<r)    swap(a[l], a[r]);
    }
    // Sort odd number in descending order 
    sort(a, a + k, greater<int>()); 
  
    // Sort even number in ascending order 
    sort(a + k, a + n); 
}


// Method 2:

int main()
{
    int arr[] = { 1, 3, 2, 7, 5, 4 }; 
    int n = sizeof(arr) / sizeof(int); 
    twoWaySort2(arr, n); 
 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0;
}