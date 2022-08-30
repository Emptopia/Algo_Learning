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

int main()
{
	test01();

	system("pause");
	return 0;
}