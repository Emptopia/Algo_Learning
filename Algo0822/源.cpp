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

void test03()
{
	Solution sln;
	TreeNode* th4 = new TreeNode(15);
	TreeNode* th5 = new TreeNode(7);
	TreeNode* rd3 = new TreeNode(20,th4,th5);
	TreeNode* nd2 = new TreeNode(9);
	TreeNode* st1 = new TreeNode(3, nd2, rd3);
	int res = sln.maxDepth(st1);
	cout << res << endl;
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}