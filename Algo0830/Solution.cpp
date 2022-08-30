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