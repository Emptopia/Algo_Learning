#include<iostream>
using namespace std;
#include"Solution.h"
#include<vector>

void test01()
{
	Solution sln;
	vector<int>nums1 = { 1, 2, 3, 0, 0, 0 };
	int m = 3;
	vector<int> nums2 = { 2, 5, 6 };
	int n = 3;
	sln.merge(nums1, m, nums2, n);
	sln.printVector(nums1);
}

void test02()
{
	Solution sln;
	int n = 5;
	int res = sln.firstBadVersion(n);
	cout << res << endl;
}

void test03()
{
	Solution sln;
	sln.climbStairs(3);
}

void test04()
{
	Solution sln;
	vector<int>nums = { 7,1,5,3,6,4 };
	int profit = sln.maxProfit(nums);
	cout << profit << endl;
}

void test05()
{
	Solution sln;
	vector<int>nums = { -2,1,-3,4,-1,2,1,-5,4 };
	int res = sln.maxSubArray(nums);
	cout << res << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	system("pause");
	return 0;
}