#include<iostream>
using namespace std;
#include"Solution.h"
#include<unordered_map>
#include<map>

void test01()
{
	Solution sln;
	string haystack = "hello";
	string needle = "ll";
	cout << sln.strStr(haystack, needle) << endl;
}

void test02()
{
	Solution sln;
	cout << sln.countAndSay(1) << endl;
	cout << sln.countAndSay(2) << endl;
	cout << sln.countAndSay(3) << endl;
	cout << sln.countAndSay(4) << endl;



}

void test03()
{
	Solution sln;
	vector<string>strs = { "flower", "flow", "flight" };
	cout << sln.longestCommonPrefix(strs) << endl;
}

int main()
{
	//test01();
	//test02();
	test03();
	return 0;
	system("pause");
}