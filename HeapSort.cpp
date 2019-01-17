#include<iostream>
using namespace std;

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void shiftUp(int arr[], int n)
{
	if (n < 1)return;
	int b = (n - 1) / 2;
	int a = n;
	while (a > 0)
	{
		if (arr[a] > arr[b])
		{
			swap(arr, a, b);
			a = b;
			b = (b - 1) / 2;
		}
		else break;
	}
}
void shiftDown(int arr[], int n)
{
	if (n < 1)
	{
		return;
	}
	int a, b = 0;
	int maxLeaf = (n - 1) / 2;
	while (b <= maxLeaf)
	{
		a = 2 * b + 1;
		if (a < n&&arr[a] < arr[a + 1])
		{
			a++;
		}
		if (arr[b] < arr[a])
		{
			swap(arr, b, a);
			b = a;
		}
		else break;
	}
}
void heapSort(int *arr , int len)
{
	int index;

	for (index = 1; index < len; index++)
	{
		shiftUp(arr, index);
	}
	for (index = len - 1; index > 0;)
	{
		swap(arr, 0, index);
		index--;
		shiftDown(arr, index);
	}
}
int main()
{
	int arr[] = { 213,43,43,123,45,52,67,234,452,5,67 };
	int len = 11;
	cout << "Before sorting:" << endl;
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl << endl;

	heapSort(arr, len);

	cout << "After Sorting:" << endl;
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;

	return 0;
}