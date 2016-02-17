/*
	Infoarena statistic order problem
	(n_th element is implemented in algorithm header)

	complexity: on averege O(n), in worst case scenario O(n^2)
	
	Idea: We use QuickSort algorithm to determine the solution.
	We observe that it is not necessarily to sort the whole array and it's
	enough to sort some parts of the array (those that are relevant to our problem)

*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <ctime>
#define N 3000009
using namespace std;
int n, k, a[N];
int quickSort(int left, int right)
{
	int mid = left + rand() % (right - left + 1) ;
	int swapedElement = a[mid];
	int i = left, j = right ;
	while (i <= j)
	{
		while (a[i] < swapedElement)
			i++;
		while (a[j] > swapedElement)
			j--;
		if (i < j) {
			swap(a[i], a[j]);
			i++, j--; // we can swap the same element and this case will cause an infinite loop
		}
		else
			return j;

	}
	return 0;
}
void stat(int left, int right, int k)
{
	if (left == right)
		return;
	int pivot_position = quickSort(left, right);
	int dist =  pivot_position - left + 1;
	if (dist >= k)
		stat(left, pivot_position, k);
	else
		stat(pivot_position + 1, right, k - dist);
}
int main()
{
	srand(time(NULL));
	fstream  g;
	FILE *f;
	f = fopen("sdo.in", "rt");
	g.open("sdo.out", ios::out);
	fscanf(f, "%d%d", &n, &k);
	int i;
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);

	stat(1, n, k);

	g << a[k];
	return 0;
}
