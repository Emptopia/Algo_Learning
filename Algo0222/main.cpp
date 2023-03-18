#include<iostream>
using namespace std;
#include"Solution.h"



void test01()
{
	Solution sln;
	string s = "joyboy";
	int res =sln.lengthOfLastWord(s);
	cout <<  res;
}

void test02()
{
	Solution sln;
	vector<int>nums = { 2,7,11,15 };
	int target = 9;
	vector<int>res = sln.twoSum(nums, target);
	sln.Tprint(res);
}

void test03()
{
	Solution sln;
	ListNode* l5 = new ListNode(5);
	ListNode* l4 = new ListNode(4,l5);
	ListNode* l3 = new ListNode(3, l4);
	ListNode* l2 = new ListNode(2, l3);
	ListNode* l1 = new ListNode(1, l2);
	ListNode* res = sln.reverseList(l1);
	sln.ListPrint(res);
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}

