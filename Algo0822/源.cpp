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

void test04()
{
	Solution sln;
	TreeNode* th4 = new TreeNode(4);
	TreeNode* th5 = new TreeNode(6);
	TreeNode* nd2 = new TreeNode(1);
	TreeNode* rd3 = new TreeNode(5, th4, th5);
	TreeNode* root = new TreeNode(3, nd2, rd3);
	bool res = sln.isValidBST(root);
	if (res == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

void test05()
{
	Solution sln;
	TreeNode* th6 = new TreeNode(4);
	TreeNode* th7 = new TreeNode(3);
	TreeNode* th4 = new TreeNode(3);
	TreeNode* th5 = new TreeNode(4);
	TreeNode* nd2 = new TreeNode(2, th6, th7);
	TreeNode* rd3 = new TreeNode(2, th4, th5);
	TreeNode* root = new TreeNode(1, nd2, rd3);
	bool res = sln.isSymmetric(root);
	if (res == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;

}

void test06()
{
	Solution sln;
	TreeNode* th6 = new TreeNode(4);
	TreeNode* th7 = new TreeNode(3);
	TreeNode* th4 = new TreeNode(3);
	TreeNode* th5 = new TreeNode(4);
	TreeNode* nd2 = new TreeNode(2, th6, th7);
	TreeNode* rd3 = new TreeNode(2, th4, th5);
	TreeNode* root = new TreeNode(1, nd2, rd3);
	vector<vector<int>> res = sln.levelOrder(root);
	sln.printVector(res);
}

void test07()
{
	Solution sln;
	vector<int>nums = { -10, -3, 0, 5, 9 };

	TreeNode* root = sln.sortedArrayToBST(nums);

	vector<vector<int>> res = sln.levelOrder(root);			//±È¿˙∫Û¥Ú”°
	sln.printVector(res);
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	system("pause");
	return 0;
}