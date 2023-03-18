using namespace std;
#include<iostream>
#include"Solution.h"
#include<vector>

void test01()
{
	Solution sln;
	vector<int>nums = { 1,1,1,3,3,4,3,2,4,2 };
	cout << sln.containsDuplicate(nums) << endl;
}

void test02()
{
	Solution sln;
	vector<int>nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << sln.maxSubArray(nums) << endl;
}

void test03()
{
	Solution sln;
	vector<int>nums = { 2,7,11,15 };
	int target = 9;
	vector<int>res = sln.twoSum(nums, target);
	sln.Tprint(res);


}

void test04()
{
	Solution sln;
	vector<int>nums1 = { 1,2,3,0,0,0 };
	vector<int>nums2 = { 2,5,6 };
	int m = 3;
	int n = 3;
	sln.merge(nums1, m, nums2, n);
	sln.Tprint(nums1);

}

void test05()
{
	Solution sln;
	vector<int>nums1 = { 1,2,2,1 };
	vector<int>nums2 = { 2,2 };
	vector<int>res = sln.intersect(nums1, nums2);
	sln.Tprint(res);
}

void test06()
{
	Solution sln;
	vector<int>nums = { 7,1,5,3,6,4 };
	int res = sln.maxProfit(nums);
	cout << res << endl;
}

void test07()
{
	Solution sln;
	vector<vector<int>>mat = { {1,2},{3,4} };
	int r = 1;
	int c = 4;
	vector<vector<int>> res = sln.matrixReshape(mat, r, c);
	sln.TTprint(mat);
	sln.TTprint(res);

}

void test08()
{
	Solution sln;
	vector<vector<int>> res = sln.generate(5);
	sln.TTprint(res);

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	system("pause");
	return 0;

}