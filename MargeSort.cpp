#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void merge(vector<int>& nums, int l1, int r1, int l2, int r2)
{
	int i = l1;
	int j = l2;
	int  n = (r1 - l1 + 1) + (r2 - l2 + 1);
	vector<int>temp(n);
	int k = 0;
	while (i <= r1 && j <= r2)
	{
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];
	for(int i = 0; i < n; i++)
		nums[l1 + i] = temp[i];

}
void MergeSort(vector<int>& nums, int start, int end) {
	if (start < end) {
		int mid = (start + end) >> 1;				//�ָ�����
		MergeSort(nums, start, mid);				//��������벿�ֽ��й沢����
		MergeSort(nums, mid + 1, end);				//�������Ұ벿�ֽ��й沢����
		merge(nums, start, mid, mid + 1, end);                  //�ϲ��Ѿ��������������
	}
}

int main() {
	vector<int> nums{ 1,4,3,2,5,6,3 };
	MergeSort(nums, 0, 6);
	for (auto x : nums)
		cout << x << " ";
	cout << endl;
	return 0;
}