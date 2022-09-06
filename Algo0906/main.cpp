#include<iostream>
using namespace std;
#include"Solution.h"
#include<vector>

void test01()
{
	vector<int>nums = { 1,2,3 };
	Solution* obj = new Solution(nums);
	vector<int>param_1 = obj->shuffle();
	vector<int>param_2 = obj->reset();
	vector<int>param_3 = obj->shuffle();

	obj->printVector(param_1);
	obj->printVector(param_2);
	obj->printVector(param_3);

}


int main()
{
	test01();

	system("pause");
	return 0;

}