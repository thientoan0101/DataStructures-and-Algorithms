// Selection Sort:


//IDEA: : -Finds the element that satisfies the requirements(minimum, maximum...) 
//								from the current position to the end of the array.
//		  - Swap these two elements.

//Steps:
// - S1: i = 0;
// - S2: Find the position of the min/max element from i to n-1;
// - S3: Swap.
// - S4 : i = i + 1.
//		   If i < n - 1 go to S2.
//         Otherwise, end

//source code in C++:

#include <algorithm>
using namespace std;

void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j]) min = j;
		}
		swap(a[min], a[i]);
	}
}