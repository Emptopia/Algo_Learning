#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
class Solution
{
public:
	template<typename T>
	void Tprint(vector<T>nums)
	{
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	template<typename T>
	void TTprint(vector<vector<T>>nums)
	{
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			for (auto itt = it->begin(); itt != it->end(); itt++)
			{
				cout << *itt << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	bool containsDuplicate(vector<int>& nums);
	int maxSubArray(vector<int>& nums);
	vector<int> twoSum(vector<int>& nums, int target);
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
	int maxProfit(vector<int>& prices);
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c);
	vector<vector<int>> generate(int numRows);
};

