// Idea: small values “bubble” up to the top of list
//			- Begin from the end of the array, in turn, swap two adjacent elements if
//			  they are in the wrong order.
//			- The lightest element will float to the top of the array, the next step
//			  doesn't take it into account.


// Steps:
//	- S1 : i = 0; //the floating surface
//	- S2: j = n - 1; //begin from end of the array
//	- S3: If a[i] and a[j - 1] are in the wrong order, swap them; //bubble
//	- S4: j = j - 1; If j > i, go back to S3. // “bubble” up to the top of list
//	- S5: i = i + 1; If i < n - 1, go back to S2.
//					Otherwise, go to end.


//source code in C++:

#include <algorithm>
using namespace std;

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{			
		for (int j = n-1; j >i; j--)
		{
			if (a[j] < a[j-1]) swap(a[j], a[j-1]);
		}		
	}
}