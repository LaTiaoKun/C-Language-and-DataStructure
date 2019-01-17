#include<iostream>
using namespace std;
int Bcount = 0;
int Pcount = 0;
void InsertSort(int* pDataArray, int iDataNum)
{
	for (int i = 1; i < iDataNum; i++)    //从第2个数据开始插入
	{
		int j = i - 1;
		int temp = pDataArray[i];    //记录要插入的数据
		while (j >= 0 && pDataArray[j] > temp)    //从后向前，找到比其小的数的位置
		{

			pDataArray[j + 1] = pDataArray[j];    //向后挪动
			j--;
		}

		if (j != i - 1)    //存在比其小的数
		{
			pDataArray[j + 1] = temp;
		}
	}
}
int main()
{
	int array[11];
	int data;
	cout << "请输入一组数据" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "第" << i+1 << "个数据";
		cin >> data;
	    InsertSort(array,data);
	}
	cout <<"移动次数"<<Pcount<< "比较次数"<<Bcount << endl;
}