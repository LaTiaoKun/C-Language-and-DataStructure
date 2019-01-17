#include<iostream>
#include<math.h>
using namespace std;


void print(int *arr, int n, int i)
{
	cout << "第" << i << "次";
	for (int j = 0; j < n; j++)
	{
		cout << " " << arr[j];
	}
	cout << endl;

}
void printResult(int *arr, int n)
{
	cout << "排序结果";
		for (int j = 0; j < n; j++)
		{
			cout << " " << arr[j];
		}
	cout << endl;
}
void binaryInsertSort(int *arr,int length)
{
	int i, j;
	for (i = 1; i < length; i++)
	{
		int temp = arr[i];
		int low = 0;
		int high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) >>1;
			if (arr[mid] > temp)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for (j = i - 1; j >= low; j--)
		{
			arr[j + 1] = arr[j];
		}
		  arr[low] = temp;
		  print(arr, length, i);
	}
	printResult(arr, length);
}
int main()
{
	
	int a[105] = {0};
	for (int i = 0; i < 105; i++)
	{
		a[i] = rand() % 1000;
	}
	int length = sizeof(a) / sizeof(int);
	binaryInsertSort(a, length);
	cin.get();
}