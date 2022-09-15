#include<iostream>
using namespace std;
#include "Solution.h"
#include <vector>
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

void test03()
{
	Solution sln;
	uint32_t num = 43261596;
	uint32_t res = sln.reverseBits(num);
	cout << res << endl;

}

void test04()
{
	Solution sln;
	int num = 5;
	vector<vector<int>>res = sln.generate(num);
	sln.printVV(res);
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