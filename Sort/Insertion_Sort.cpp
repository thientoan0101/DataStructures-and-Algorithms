//Idea: 
//	- Suppose that a0, …, ai has the order, find the position to insert element a(i+1)
//	  into that sequence such that it still has order.

//Steps:
//	- S1 : i = 1; (a[0] sorted because there is only 1 element).
//	- S2: x = a[i];
//	- S3: Find position pos to insert x into the array from a[0] to a[i - 1];
//	- S4: Move the elements from a[pos] to a[i - 1] to the right by 1 position
//		  to accommodate the insertion of x in this pos position.
//	- S5 : a[pos] = x;
//	- S6: i = i + 1; 
//			If i < n, go to S2.
//			therwise, go to end


// Source code in c++:
#include <algorithm>
using namespace std;

void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int pos = i - 1;
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}