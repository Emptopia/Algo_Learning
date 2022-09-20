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

void test04()
{
	Solution sln;
	//vector<vector<int>>matrix = 
	//{ { 5, 1, 9,11 },
	//{ 2, 4, 8,10 },
	//{ 13, 3, 6, 7 },
	//{ 15,14,12,16 } };
	vector<vector<int>>matrix =
	{ {1, 2}, { 3, 4 }};
	//vector<vector<int>>matrix =
	//{
	//	{1,2,3},
	//	 {4,5,6},
	//	{7,8,9}
	//};
	sln.VVprint(matrix);
	sln.rotate(matrix);
	sln.VVprint(matrix);
}

void test05()
{
	Solution sln;
	vector<vector<int>>matrix =
	{
		{ 0,1,2,0 },
		{ 3,4,5,2 },
		{ 1,3,1,5 }
	};
	sln.setZeroes(matrix);
	sln.VVprint(matrix);
}

void test06()
{
	Solution sln;
	//vector<vector<int>>mat = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	vector<vector<int>>mat = { {2,3} };
	vector<int>res = sln.findDiagonalOrder(mat);
	sln.Vprint(res);
}


int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return 0;
}