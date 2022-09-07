#include<iostream>
using namespace std;
#include"Solution.h"
#include<vector>
#include"MinStack.h"
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

void test02()
{
	MinStack* minStack = new MinStack();
	minStack->push(-2);
	minStack->push(0);
	minStack->push(-3);
	cout << minStack->getMin() << endl; //-- > ·µ»Ø - 3.
	minStack->pop();
	cout << minStack->top() << endl;     // -- > ·µ»Ø 0.
	cout << minStack->getMin() << endl;			//·µ»Ø -2.


}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;

}