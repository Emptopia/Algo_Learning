#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>

class Solution
{
public:
	void printVector(vector<int>& nums);

	bool containsDuplicate(vector<int>& nums);
	int singleNumber(vector<int>& nums);
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
	vector<int> plusOne(vector<int>& digits);
	void moveZeroes(vector<int>& nums);
	vector<int> twoSum(vector<int>& nums, int target);
};