#include<iostream>
using namespace std;
#include<vector>
#include"Solution.h"

void test01()
{
	Solution sln;
	vector<int> nums = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
	if (sln.containsDuplicate(nums))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

void test02()
{
	Solution sln;
	vector<int>nums = { 1,1,2,3,3 };
	//vector<int>nums = { 2,2,1};

	cout << sln.singleNumber(nums) << endl;
}

void test03()
{
	Solution sln;
	//vector<int>nums1 = { 4,9,5 };
	//vector<int>nums2 = { 9,4,9,8,4 };
	vector<int>nums1 = { 1,2,2,1 };
	vector<int>nums2 = { 2,2 };

	vector<int>nums3 = sln.intersect(nums1, nums2);
	sln.printVector(nums3);
}

void test04()
{
	Solution sln;
	vector<int>digits = { 4,3,2,1 };
	vector<int>res = sln.plusOne(digits);
	sln.printVector(res);

}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return 0;
}