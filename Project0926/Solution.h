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


	int removeElement(vector<int>& nums, int val);
	int findMaxConsecutiveOnes(vector<int>& nums);
	int minSubArrayLen(int target, vector<int>& nums);
};

