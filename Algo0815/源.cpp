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

void test04()
{
	Solution sln;


	Solution::ListNode* L = new Solution::ListNode(4);
	Solution::ListNode* l1 = new Solution::ListNode(5);
	Solution::ListNode* l2 = new Solution::ListNode(1);
	Solution::ListNode* l3 = new Solution::ListNode(9);
	L->next = l1;
	l1->next = l2;
	l2->next = l3;
	sln.deleteNode(l1);
	sln.printLinkList(L);

}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
	system("pause");
}