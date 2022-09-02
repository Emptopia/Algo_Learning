#pragma once
#include<iostream>
using namespace std;
#include<vector>

class Solution
{
public:
	void printVector(vector<int>nums);

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
	int firstBadVersion(int n);
	bool isBadVersion(int bad);
	int climbStairs(int n);
	int maxProfit(vector<int>& prices);
};

