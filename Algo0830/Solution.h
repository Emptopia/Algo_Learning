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
	int maxSubArray(vector<int>& nums);
	int rob(vector<int>& nums);

    vector<int> origin;
    vector<int> current;
    int n;

    Solution() {}

    Solution(vector<int>& nums) {
        origin = nums;
        current = nums;
        n = nums.size();
    }

    vector<int> reset() {
        current = origin;
        return current;
    }

    vector<int> shuffle() {
        for (int i = 0; i < n; i++) {
            int tmp;
            int target = i + rand() % (n - i);
            tmp = current[i];
            current[i] = current[target];
            current[target] = tmp;
        }
        return current;
    }
};

