#include<iostream>
using namespace std;
#include "Solution.h"
#include<vector>

void test01()
{
	Solution sln;
	vector<int>nums = { 1, 7, 3, 6, 5, 6 };
	int res = sln.pivotIndex(nums);
	cout << res << endl;
}

void test02()
{
	Solution sln;
	vector<int>nums = { 1,3,5,6 };
	int target = 5;
	int res = sln.searchInsert(nums, target);
	cout << res << endl;

}

void test03()
{
	Solution sln;
	vector<vector<int>>intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
	vector<vector<int>>res = sln.merge(intervals);
	sln.VVprint(res);

}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}