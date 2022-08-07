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

void test05()
{
	Solution sln;
	vector<int>nums = { 0, 1, 0, 3, 12 };
	sln.moveZeroes(nums);
	sln.printVector(nums);

}

void test06()
{
	Solution sln;
	vector<int>nums = { 2,7,11,15 };
	int target = 9;
	vector<int>nums2;

	nums2 = sln.twoSum(nums, target);
	sln.printVector(nums2);
}

void test07()
{
	Solution sln;


	vector<vector<char>> board =
		  { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
		, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
		, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
		, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
		, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
		, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
		, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
		, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
		, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	if (sln.isValidSudoku(board))
	{
		cout << "有效！" << endl;
	}
	else
	{
		cout << "无效！！" << endl;
	}

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();


	system("pause");
	return 0;
}