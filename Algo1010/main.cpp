#include<iostream>
using namespace std;
#include"Solution.h"
#include<vector>

void test01()
{
	Solution sln;
	vector<vector<int>>matrix =
	{
			{1, 4, 7, 11, 15},
			{2, 5, 8, 12, 19},
			{3, 6, 9, 16, 22},
			{10, 13, 14, 17, 24},
			{18, 21, 23, 26, 30}
	};
	cout << sln.findNumberIn2DArray(matrix, 5) << endl;				//true ,1
	cout << sln.findNumberIn2DArray(matrix, 20) << endl;			//false,0
}

void test02()
{
	Solution sln;
	vector<int>numbers = { 3, 4, 5, 1, 2 };
	cout << sln.minArray(numbers) << endl;
}

void test03()
{
	Solution sln;
	string s = "leetcode";
	cout << sln.firstUniqChar(s) << endl;
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}