#pragma once
#include<iostream>
using namespace std;
#include<vector>


class Solution
{
public:
	template <typename T>
	void Tprint(T nums)
	{
		for (auto it = nums.begin(); it != nums.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	template <typename T>
	void TTprint(T nums)
	{
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			for (auto itt = it->begin(); itt != it->end(); itt++)
				cout << *itt << " ";
			cout << endl;
		}
	}

	int removeElement(vector<int>& nums, int val);
	int findMaxConsecutiveOnes(vector<int>& nums);
	int minSubArrayLen(int target, vector<int>& nums);
	vector<vector<int>> generate(int numRows);
	vector<int> getRow(int rowIndex);
	int findMin(vector<int>& nums);
	string reverseWords(string s);
	int removeDuplicates(vector<int>& nums);
	void moveZeroes(vector<int>& nums);
};

