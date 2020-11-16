#include <iostream>
using namespace std;


void sort2D(int a[][3], int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-1;j++)
            for (int k = j+1; k<n;k++)
                if (a[i][j]>a[i][k])  swap(a[i][j],a[i][k]);
    }
}

void print2D(int a[][3], int n)
{
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<n;j++) 
            cout<<a[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int a[3][3] = { {5, 4, 7}, {1, 3, 8}, {2, 9, 6} };
    int n = 3;
    print2D(a,n);
    sort2D(a,n);

    print2D(a,n);
    return 0;
}
