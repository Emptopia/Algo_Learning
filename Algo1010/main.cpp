#include<iostream>
using namespace std;
#include"Solution.h"
#include<vector>

void test01()
{
	Solution sln;
	vector<vector<int>>matrix =
	{
			{1, 4, 7, 11, 15},
			{2, 5, 8, 12, 19},
			{3, 6, 9, 16, 22},
			{10, 13, 14, 17, 24},
			{18, 21, 23, 26, 30}
	};
	cout << sln.findNumberIn2DArray(matrix, 5) << endl;				//true ,1
	cout << sln.findNumberIn2DArray(matrix, 20) << endl;			//false,0
}

void test02()
{
	Solution sln;
	vector<int>numbers = { 3, 4, 5, 1, 2 };
	cout << sln.minArray(numbers) << endl;
}

void test03()
{
	Solution sln;
	string s = "leetcode";
	cout << sln.firstUniqChar(s) << endl;
}

void test04()
{
	TreeNode* T7 = new TreeNode(7);
	TreeNode* T6 = new TreeNode(15);
	TreeNode* T3 = new TreeNode(20);
	T3->left = T6;
	T3->right = T7;
	TreeNode*T2 = new TreeNode(9);
	TreeNode*T1 = new TreeNode(3);
	T1->left = T2;
	T1->right = T3;

	Solution sln;
	vector<int>res = sln.levelOrder(T1);
	sln.Tprint(res);

}

void test05()
{
	TreeNode* T7 = new TreeNode(7);
	TreeNode* T6 = new TreeNode(15);
	TreeNode* T3 = new TreeNode(20);
	T3->left = T6;
	T3->right = T7;
	TreeNode* T2 = new TreeNode(9);
	TreeNode* T1 = new TreeNode(3);
	T1->left = T2;
	T1->right = T3;

	Solution sln;
	vector<vector<int>>res = sln.levelOrder2(T1);
	sln.TTprint(res);


}

void test06()
{
	TreeNode* T7 = new TreeNode(7);
	TreeNode* T6 = new TreeNode(15);
	TreeNode* T3 = new TreeNode(20);
	T3->left = T6;
	T3->right = T7;
	TreeNode* T2 = new TreeNode(9);
	TreeNode* T1 = new TreeNode(3);
	T1->left = T2;
	T1->right = T3;

	Solution sln;
	vector<vector<int>>res = sln.levelOrder2(T1);
	sln.TTprint(res);


}

void test07()
{
	TreeNode* T1 = new TreeNode(3);
	TreeNode* T2 = new TreeNode(4);
	TreeNode* T3 = new TreeNode(5);
	T1->left = T2;
	T1->right = T3;
	TreeNode* T4 = new TreeNode(1);
	TreeNode* T5 = new TreeNode(2);
	T2->left = T4;
	T2->right = T5;

	TreeNode* TT1 = new TreeNode(4);
	TreeNode* TT2 = new TreeNode(1);
	TT1->left = TT2;

	Solution sln;
	cout << sln.isSubStructure(T1, TT1) << endl;
}

void test08()
{
	TreeNode* T1 = new TreeNode(3);
	TreeNode* T2 = new TreeNode(4);
	TreeNode* T3 = new TreeNode(5);
	T1->left = T2;
	T1->right = T3;
	TreeNode* T4 = new TreeNode(1);
	TreeNode* T5 = new TreeNode(2);
	T2->left = T4;
	T2->right = T5;

	Solution sln;
	vector<vector<int>>res = sln.levelOrder2(sln.mirrorTree(T1));
	sln.TTprint(res);

}

void test09()
{
	TreeNode* T1 = new TreeNode(1);
	TreeNode* T2 = new TreeNode(2);
	TreeNode* T3 = new TreeNode(2);
	T1->left = T2;
	T1->right = T3;
	TreeNode* T4 = new TreeNode(3);
	TreeNode* T5 = new TreeNode(4);
	T2->left = T4;
	T2->right = T5;
	TreeNode* T6 = new TreeNode(4);
	TreeNode* T7 = new TreeNode(3);
	T3->left = T6;
	T3->right = T7;

	Solution sln;
	cout << sln.isSymmetric(T1) << endl;

}

void test10()
{
	Solution sln;
	cout << sln.fib(5) << endl;
}

void test11()
{
	Solution sln;
	cout << sln.numWays(7) << endl;

}

void test12()
{

	Solution sln;
	vector<int>nums = { 7,1,5,3,6,4 };
	cout << sln.maxProfit(nums) << endl;
}

void test13()
{
	Solution sln;
	vector<int>nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << sln.maxSubArray(nums) << endl;
}

void test14()
{
	Solution sln;
	vector<vector<int>>grid =
	{
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}
	};
	cout << sln.maxValue(grid) << endl;


}

void test15()
{
	Solution sln;
	int num = 12258;
	cout << sln.translateNum(num) << endl;
}

void test16()
{
	Solution sln;
	string s = "aab";
	cout << sln.lengthOfLongestSubstring(s) << endl;

	string s2 = "pwwkew";
	cout << sln.lengthOfLongestSubstring(s2) << endl;
	string s3 = "dvdf";
	cout << sln.lengthOfLongestSubstring(s3) << endl;

}

void test17()
{
	ListNode* L1 = new ListNode(4);
	ListNode* L2 = new ListNode(5);
	ListNode* L3 = new ListNode(1);
	ListNode* L4 = new ListNode(9);

	L1->next = L2;
	L2->next = L3;
	L3->next = L4;
	int val = 5;
	Solution sln;
	sln.LNprint(L1);
	ListNode* head = sln.deleteNode(L1, val);
	sln.LNprint(head);

}

void test18()
{
	ListNode* L1 = new ListNode(1);
	ListNode* L2 = new ListNode(2);
	ListNode* L3 = new ListNode(3);
	ListNode* L4 = new ListNode(4);
	ListNode* L5 = new ListNode(5);

	L1->next = L2;
	L2->next = L3;
	L3->next = L4;
	L4->next = L5;

	int k = 2;
	Solution sln;
	ListNode* head = sln.getKthFromEnd(L1, k);
	sln.LNprint(head);

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
	//test12();
	//test13();
	//test14();
	//test15();
	//test16();
	//test17();
	test18();
	system("pause");
	return 0;
}