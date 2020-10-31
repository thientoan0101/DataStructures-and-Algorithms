// Source code in c++:
#include <algorithm>
using namespace std;

void interchangeSort(int a[], int n)
{
	for (int i = 0; i<n-1;i++)
		for (int j = i + 1; j < n; j++)
		{
			if (a[i > a[j]])	swap(a[i], a[j]);
		}
}