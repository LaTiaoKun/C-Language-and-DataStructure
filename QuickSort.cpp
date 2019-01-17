#include <iostream>

void QuickSort(int *arr, int l, int r)
{
	int len = r;        // �洢��ǰ��������һ��Ԫ�ص�����
	int num = arr[l];   // �����������Ԫ��
	bool dir = 0;       // ������ʾ�ƶ�����

						/*һ�˿�������*/
	while (l != r)
	{
		if (dir == 0)
		{
			if (arr[r] < num)
			{
				arr[l] = arr[r];
				dir = 1;
			}
			else
			{
				r--;
			}
		}
		else
		{
			if (arr[l] > num)
			{
				arr[r] = arr[l];
				dir = 0;
			}
			else
			{
				l++;
			}
		}
	}
	arr[l] = num;               // ������Ԫ�ط�������λ��
	if (l > 1)
	{
		QuickSort(arr, 0, l - 1);
	}
	if (len - l - 1 > 1)
	{
		QuickSort(arr, l + 1, len);
	}
}

int main()
{
	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int len = 8;
	QuickSort(arr, 0, len - 1);

	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}