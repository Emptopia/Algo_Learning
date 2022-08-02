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
	vector<int>nums = { 4,1,2,1,2 };
	cout << sln.singleNumber(nums) << endl;
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}