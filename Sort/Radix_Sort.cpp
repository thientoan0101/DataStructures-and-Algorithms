#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;




int findNumDigit(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (max < a[i]) max = a[i];

    int d = 0;
    while (max > 0)
    {
        d++;
        max = max / 10;
    }
    return d;
}


void radixSort(int a[], int n)
{
    queue<int> B[10];

    int mDigit = findNumDigit(a, n);

    for (int exp = 0; exp < mDigit; exp++)
    {
        for (int i = 0; i < n; i++)
        {
            int digit = a[i] / (int)pow(10, exp) % (10);
            B[digit].push(a[i]);
        }
        int i = 0;
        for (int j = 0; j <= 9; j++)
        {
            while (!B[j].empty())
            {
                a[i++] = B[j].front();
                B[j].pop();
            }
        }
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
}




int main()
{
    int a[] = { 329, 457,657,839,1,54,53,18,200,87,34,4,436,720,355 };
    int n = 15;
    print(a, n);
    radixSort(a, n);
    print(a, n);

    return 0;
}