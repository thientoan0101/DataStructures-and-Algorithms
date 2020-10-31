// Bidirectional Bubble Sort, Cocktail Sort.
// Idea: the light elements will float, the heavy ones will sink
//	- Similar to Bubble sort, but in addition to sinking heavy elements.
//	- There are also improvements, reducing redundant comparisons by :
//		+ The floating surface for the next stage will be where the last floating swapping occurred.
//		+ The sink bottom for the next stage will be where the last sink swapping occurs


// Steps:
//	- S1 : surface = 0; //the floating surface
//		   bottom = n - 1; //the sinking bottom
//		   k = n - 1; //saves the location where the last swapping occurred
//	- S2: j = bottom; //push the light element up from the bottom
//			- S2a: If a[j] and a[j - 1] are in wrong order, swap them; //floating
//				   and k = j; // save where the permutation occurs
//			- S2b: j = j - 1; If j > surface, go to S2. // floating to the surface
//	- S3: surface = k; // the new surface is the last swapping because the previous	sequence is ordered
//	- S4: j = surface;
//			- S4a: If a[j] and a[j + 1] are in wrong order, swap them; //sinking
//					and k = j;
//			- S4b: j = j + 1; If j < bottom, go to S4.
//	- S5: bottom = k;
//	- S6: If surface < bottom, go to S2.Otherwise, go to end.


//source code in C++:

#include <algorithm>
using namespace std;

void ShakerSort(int a[], int n)
{
    int surface = 0, bottom = n - 1, k = n - 1;
    while (surface < bottom)
    {
        for (int i = bottom; i > surface; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        surface = k;

        for (int i = surface; i < bottom; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        bottom = k;
    }
}