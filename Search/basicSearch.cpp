#include <iostream>
#include <algorithm>
using namespace std;



int sentinelSearch(int a[], int n, int x)
{
    int last = a[n-1];
    a[n-1] = x;
    int i = 0;
    while (a[i]!=x)
        i++;
    a[n-1] = last;
    if (i<n-1 || a[n-1]==x)
        return i;  
    return -1; 
}

int binarySearch(int a[], int n, int x)
{    
    int left = 0, right = n-1;

    while (left<=right)
    {
        int mid = left + (right - left)/2;
        if (a[mid]==x) return mid;
        if (a[mid]>x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}


int main()
{
    int a[] = {3,6,0,5,7,8,5,4,3,24,6,7};
    int n = 12;
    sort(a,a+n);
    cout << binarySearch(a,n,24);
    return 0;
}