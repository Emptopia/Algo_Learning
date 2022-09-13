#include<iostream>
using namespace std;
#include "Solution.h"

void test01()
{
	Solution sln;
	uint32_t num = 00000000000000000000000000001011;
	int res = sln.hammingWeight(num);
	cout << res << endl;
}

void test02()
{
	Solution sln;
	int x = 1;
	int y = 4;
	int res = sln.hammingDistance(x, y);
	cout << res << endl;

}



int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}