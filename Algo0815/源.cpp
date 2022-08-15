#include<iostream>
using namespace std;
#include"Solution.h"

void test01()
{
	Solution sln;
	string haystack = "hello";
	string needle = "ll";
	cout << sln.strStr(haystack, needle) << endl;
}

int main()
{
	test01();


	return 0;
	system("pause");
}