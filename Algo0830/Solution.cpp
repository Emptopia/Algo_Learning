#include "Solution.h"

void Solution::printVector(vector<int>nums)
{
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int>res = vector<int>();
	int left = 0;
	int right = 0;
	while (left != m && right != n)
	{
		if (nums1[left] < nums2[right])
		{
			res.push_back(nums1[left]);
			left++;
		}
		else
		{
			res.push_back(nums2[right]);
			right++;
		}
	}
	if (left == m )
	{
		while (right != n )
		{
			res.push_back(nums2[right]);
			right++;
		}
	}
	else
	{
		while (left != m )
		{
			res.push_back(nums1[left]);
			left++;
		}
	}
	
	nums1 = res;
}

int Solution::firstBadVersion(int n)
{
	int left = 1, right = n;
	while (left < right)	// ѭ��ֱ���������Ҷ˵���ͬ
	{ 
		int mid = left + (right - left) / 2; // ��ֹ����ʱ���
		if (isBadVersion(mid)) 
		{
			right = mid; // �������� [left, mid] ��
		}
		else 
		{
			left = mid + 1; // �������� [mid+1, right] ��
		}
	}
	// ��ʱ�� left == right��������Ϊһ���㣬��Ϊ��
	return left;

}

bool Solution::isBadVersion(int version)
{
	int bad = 4;
	if (version >= bad)
		return true;
	else
		return false;
}