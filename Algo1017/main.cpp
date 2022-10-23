#include<iostream>
using namespace std;
#include"Solution.h"
#include<vector>

void test01()
{
	ListNode* L1 = new ListNode(1);
	ListNode* L2 = new ListNode(2);
	ListNode* L3 = new ListNode(4);
	L1->next = L2;
	L2->next = L3;

	ListNode* LL1 = new ListNode(1);
	ListNode* LL2 = new ListNode(3);
	ListNode* LL3 = new ListNode(4);
	LL1->next = LL2;
	LL2->next = LL3;

	Solution sln;
	ListNode* res = sln.mergeTwoLists(L1, LL1);
	sln.Lprint(res);
}

void test02()
{
	ListNode* L1 = new ListNode(4);
	ListNode* L2 = new ListNode(1);
	ListNode* L3 = new ListNode(8);
	ListNode* L4 = new ListNode(4);
	ListNode* L5 = new ListNode(5);

	L1->next = L2;
	L2->next = L3;
	L3->next = L4;
	L4->next = L5;
	ListNode* LL1 = new ListNode(5);
	ListNode* LL2 = new ListNode(0);
	ListNode* LL3 = new ListNode(1);


	LL1->next = LL2;
	LL2->next = LL3;
	LL3->next = L3;


	Solution sln;
	ListNode* res = sln.getIntersectionNode(L1, LL1);
	cout << res->val << endl;
}

void test03()
{
	Solution sln;
	vector<int>nums = { 1,2,3,4 };
	vector<int>res = sln.exchange(nums);
	sln.Tprint(res);
}

void test04()
{
	Solution sln;
	vector<int>nums = { 2,7,11,15 };
	int target = 9;
	vector<int>res = sln.twoSum(nums, target);
	sln.Tprint(res);
}

void test05()
{
	string s = "     ";
	Solution sln;
	string res = sln.reverseWords(s);
	cout << res << 'q' << endl;

}

void test06()
{
	Solution sln;
	//vector<vector<char>>board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	//string word = "ABCB";		//false
	vector<vector<char>>board = { {'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'} };
	string word = "ABCESEEEFS";			//true
	//vector<vector<char>>board = { {'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'} };
	//string word = "AAB";
	cout << sln.exist(board, word) << endl;

}

void test07()
{
	Solution sln;
	//int m = 2, n = 3, k = 1;
	//int res = sln.movingCount(m, n, k);
	int m = 16, n = 8, k = 4;
	int res = sln.movingCount(m, n, k);
	cout << res << endl;


}

void test08()
{
	Solution sln;
	TreeNode* N7 = new TreeNode(7);
	TreeNode* N8 = new TreeNode(2);
	TreeNode* N9 = new TreeNode(5);
	TreeNode* N10 = new TreeNode(1);

	TreeNode* N4 = new TreeNode(11, N7, N8);
	TreeNode* N5 = new TreeNode(13);
	TreeNode* N6 = new TreeNode(4, N9, N10);

	TreeNode* N2 = new TreeNode(4, N4, nullptr);
	TreeNode* N3 = new TreeNode(8, N5, N6);

	TreeNode* N1 = new TreeNode(5, N2, N3);

	vector<vector<int>>res  = sln.pathSum(N1,22);
	sln.TTprint(res);

}

void test09()
{
	Solution sln;
	Node* N4 = new Node(1);
	Node* N5 = new Node(3);

	Node* N2 = new Node(2, N4, N5);
	Node* N3 = new Node(5);

	Node* N1 = new Node(4, N2, N3);

	Node* res = sln.treeToDoublyList(N1);
	cout << "res->val = " << res->val << endl;
	cout << "res->left->val = " << res->left->val << endl;
	cout << "res->right->val = " << res->right->val << endl;


}

void test10()
{
	Solution sln;
	TreeNode* N7 = new TreeNode(7);
	TreeNode* N8 = new TreeNode(2);
	TreeNode* N9 = new TreeNode(5);
	TreeNode* N10 = new TreeNode(1);

	TreeNode* N4 = new TreeNode(11, N7, N8);
	TreeNode* N5 = new TreeNode(13);
	TreeNode* N6 = new TreeNode(4, N9, N10);

	TreeNode* N2 = new TreeNode(4, N4, nullptr);
	TreeNode* N3 = new TreeNode(8, N5, N6);

	TreeNode* N1 = new TreeNode(5, N2, N3);
	cout << sln.kthLargest(N1, 1) << endl;
}

void test11()
{
	Solution sln;
	//vector<int>nums = { 10 };
	vector<int>nums = { 3,30,34,5,9 };
	string res  = sln.minNumber(nums);
	cout << res << endl;
}

void test12()
{
	Solution sln;
	//vector<int>nums = { 8,7,11,0,9 };
	vector<int>nums = { 0,0,2,2,5 };
	cout << sln.isStraight(nums) << endl;

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	//test11();
	test12();
	system("pause");
	return 0;

}