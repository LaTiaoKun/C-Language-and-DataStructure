#include<iostream>
using namespace std;
int Bcount = 0;
int Pcount = 0;
void InsertSort(int* pDataArray, int iDataNum)
{
	for (int i = 1; i < iDataNum; i++)    //�ӵ�2�����ݿ�ʼ����
	{
		int j = i - 1;
		int temp = pDataArray[i];    //��¼Ҫ���������
		while (j >= 0 && pDataArray[j] > temp)    //�Ӻ���ǰ���ҵ�����С������λ��
		{

			pDataArray[j + 1] = pDataArray[j];    //���Ų��
			j--;
		}

		if (j != i - 1)    //���ڱ���С����
		{
			pDataArray[j + 1] = temp;
		}
	}
}
int main()
{
	int array[11];
	int data;
	cout << "������һ������" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "��" << i+1 << "������";
		cin >> data;
	    InsertSort(array,data);
	}
	cout <<"�ƶ�����"<<Pcount<< "�Ƚϴ���"<<Bcount << endl;
}