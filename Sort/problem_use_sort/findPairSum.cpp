#include <iostream>
#include <vector>
#include <set>
using namespace std;



// check array has two items which sum is equal to K-sum.
// [1,2,3,7], sum = 8:    --> NO
// [1,2,4,4], sum = 8:    --> YES



bool hasPairWithSum1(vector<int> a, int sum)                           // Big-O:  O(n^2)
{
    for (int i=0;i<a.size()-1;i++)
        for (int j =i+1; j<a.size();j++)
        {
            if (a[i]+a[j]==sum) return true;
        }
    return false;
}


int binarySearch(vector<int> a, int l, int r, int x)
{
    while (l<=r)
    {
        int mid = l+(r-l)/2;
        if (a[mid]==x)  return mid;
        if (x<a[mid]) r = mid-1;
        else l = mid + 1;
    }
    return -1;
}


bool hasPairWithSum2(vector<int> a, int sum)               // use with ordered array, BigO = O(nlogn)
{
    for (int i = 0; i<a.size()-1;i++)
    {
        int pos = binarySearch(a, i+1,a.size()-1, sum - a[i]);
        if (pos!=-1)    return true;
    }
    return false;
}


bool hasPairWithSum3(const int vector<int> a, int sum)                //use with ordered array: BigO = O(n)
{
    int low = 0, hight = a.size()-1;

    while (low<hight)
    {        
        int s = a[low]+a[hight];
        if (s == sum) return true;
        if (sum<s]) hight--;
        else low++;
    }
    return false;
}

bool hasPairWithSum4(const int vector<int> a, int sum)              // Base on HashTable, bigO = O(n)
{
    unorder_set<int> comp;

    for (int value: a)
    {
        if (comp.find(value) != comp.end)   return true;
        comp.add(sum - value); 
    }
    return false;
}