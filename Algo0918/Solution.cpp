#include "Solution.h"

void Solution::VVprint(vector<vector<int>>v)
{
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator itt = it->begin(); itt != it->end(); itt++)
		{
			cout << *itt << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Solution::pivotIndex(vector<int>& nums)
{
	//1��ǰ�����
	//int len = nums.size();
	//int prev = 0;
	//int back = accumulate(nums.begin(), nums.end(), 0);			//numeric ͷ�ļ�
	//for (int i = 0; i < len; i++)
	//{
	//	back -= nums[i];
	//	if (prev == back)
	//		return i;
	//	prev += nums[i];
	//}
	//return -1;


	//2����ǰ׺��					//���ӶȲ��
	int len = nums.size();
	int prev = 0;
	int total = accumulate(nums.begin(), nums.end(), 0);
	for (int i = 0; i < len; i++)
	{
		if (2 * prev + nums[i] == total)			//ǰ׺*2 + ��ǰ�±��� = �ܺ�
			return i;
		prev += nums[i];
	}
	return -1;
}

int Solution::searchInsert(vector<int>& nums, int target)
{
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		if (nums[i] >= target)
			return i;
	}
	return len;
}

bool Solution::isMerge(vector<int>v1, vector<int>v2)
{
	return ((v2[0] <= v1[1] && v2[0] >= v1[0])
		|| (v2[1] <= v1[1] && v2[1] >= v1[0])
		|| (v1[0] <= v2[1] && v1[0] >= v2[0])
		|| (v1[1] <= v2[1] && v1[1] >= v2[0]));
}

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals)
{
	sort(intervals.begin(), intervals.end());
	vector<vector<int>>res;
	for (int i = 0; i < intervals.size(); i++)
	{
		int L = intervals[i][0], R = intervals[i][1];
		if (!res.size() || res.back()[1] < L)					//û��ԭ���� �� �¸�������� С�� ԭ�����Ҷ�ʱ
			res.push_back(intervals[i]);						//�����¸�����
		else
		{
			res.back()[1] = max(res.back()[1], R);		//ԭ�����Ҷ˸ĳ� ����Ҷ�
		}
	}
	return res;
}

void Solution::rotate(vector<vector<int>>& matrix)
{
	int len = matrix.size();
	int temp;
	for (int j = 0; j < len - 1; j++)
	{
		for (int i = 0; i < len - 1- 2*j ; i++)
		{
			temp = matrix[j][j + i];
			matrix[j][j + i] = matrix[len - 1 - i - j][j];
			matrix[len - 1 - i - j][j] = matrix[len - 1 - j][len - 1 - i - j];
			matrix[len - 1 - j][len - 1 - i - j] = matrix[i + j][len - 1 - j];
			matrix[i + j][len - 1 - j] = temp;
		}
	}

}