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


int main()
{
	test01();


	system("pause");
	return 0;
}