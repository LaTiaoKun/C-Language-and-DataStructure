#include <stdio.h>
void Shell_Sort(int a[], int n)
{
	int i, j, d;
	for (d = n / 2; d>0; d /= 2)
	{
		for (i = d; i<n; ++i)
		{
			int temp = a[i];
			for (j = i; j >= d && a[j - d]>temp; j -= d)
				a[j] = a[j - d];
			a[j] = temp;
		}
	}
}
int main()
{
	int a[] = { 49,38,65,97,76,13,27,49,55,4 };
	int n = sizeof(a) / sizeof(int), i;
	Shell_Sort(a, n);
	for (i = 0; i<n; i++)
		printf("%d ", a[i]);
	return 0;
}