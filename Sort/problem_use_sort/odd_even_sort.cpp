//PROBLEM: Sort integer array with even numbers in ascending order and odd numbers in descending order. 
//
//Notes that, positions of even and odd parts is no change.  
//For example: 1 2 4 7 15 18 8 9 11 
//After sorting: 15 2 4 11 9 8 18 7 1 


#include <iostream>
using namespace std;


void interchangeSort(int a[], int n)
{
    for (int i = 0; i<n-1;i++)
    {
        if (a[i]%2==0)
        {
            for (int j = i+1;j<n;j++)
                if (a[j]%2==0 && a[i]>a[j])
                {
                    swap(a[i],a[j]);
                }
        } 
        else { 
            for (int j = i+1;j<n;j++)
                if (a[j]%2!=0 && a[i]<a[j])
                {
                    swap(a[i],a[j]);
                }
        }
    }
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i<n-1;i++)
    {
        if (a[i]%2==0)
        {
            int min = i;
            for (int j = i+1; j<n;j++)
            {
                if (a[j]%2==0 && a[j]<a[min]) min = j;
            }
            swap(a[i], a[min]);
        }
        else {
            int max = i;
            for (int j = i+1; j<n;j++)
            {
                if (a[j]%2!=0 && a[j]>a[max]) max = j;
            }
            swap(a[i], a[max]);
        }
    }
}


void printArr(int a[], int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

int main()
{
    int a[] = {1, 2, 4, 7, 15, 18, 8, 9, 11};
    //output: {15, 2, 4, 11, 9, 8, 18, 7, 1};
    int n = 9;

    printArr(a,n);
    selectionSort(a,n);
    
    printArr(a,n);


}