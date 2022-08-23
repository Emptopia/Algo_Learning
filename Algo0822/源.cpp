#include<iostream>
using namespace std;
#include"Solution.h"
#include<vector>

void test01()
{
	Solution sln;

	ListNode* th4 = new ListNode(1);
	ListNode* rd3 = new ListNode(2, th4);
	ListNode* nd2 = new ListNode(2, rd3);
	ListNode* st1 = new ListNode(1, nd2);
	sln.printLinkList(st1);

	vector<int> n = {3, 2, 2, 3};
	ListNode* list = sln.LinkList(n);
	sln.printLinkList(list);
	if (sln.isPalindrome(list) == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

void test02()
{
	Solution sln;

	ListNode* th4 = new ListNode(-4);
	ListNode* rd3 = new ListNode(0, th4);
	ListNode* nd2 = new ListNode(2, rd3);
	ListNode* st1 = new ListNode(3, nd2);
	th4->next = nd2;
	sln.hasCycle(st1);

}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}