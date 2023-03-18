#include"Solution.h"
#include<iostream>
using namespace std;

void test01()
{
	Solution sln;
	string s1 = "[";
	cout << sln.isValid(s1) << endl;
	string s2 = "()[]{}";
	cout << sln.isValid(s2) << endl;
	string s3 = "(]";
	cout << sln.isValid(s3) << endl;
}

void test02()
{
	Solution sln;
	int x1 = 121;
	cout << sln.isPalindrome(x1) << endl;
	int x2 = -121;
	cout << sln.isPalindrome(x2) << endl;
	int x3 = 10;
	cout << sln.isPalindrome(x3) << endl;
}

void test03()
{
	Solution sln;
	vector<int>nums1 = { 1,1,2 };
	vector<int>nums2 = { 0,0,1,1,1,2,2,3,3,4 };
	cout << sln.removeDuplicates(nums1) << endl;
	sln.Tprint(nums1);
	cout << sln.removeDuplicates(nums2) << endl;
	sln.Tprint(nums2);
}

void test04()
{
	Solution sln;
	vector<int>nums1 = { 3,2,2,3 };
	int val1 = 3;
	cout << sln.removeElement(nums1, val1) << endl;
	sln.Tprint(nums1);
	vector<int>nums2 = { 0,1,2,2,3,0,4,2 };
	int val2 = 2;
	cout << sln.removeElement(nums2, val2) << endl;
	sln.Tprint(nums2);
}

void test05()
{
	Solution sln;
	vector<int>n1 = { 1,3,5,6 };
	int t1 = 5;
	cout << sln.searchInsert(n1, t1) << endl;
	int t2 = 2;
	cout << sln.searchInsert(n1, t2) << endl;
	int t3 = 7;
	cout << sln.searchInsert(n1, t3) << endl;
}

void test06()
{
	Solution sln;
	ListNode* l1 = new ListNode(4);
	ListNode* l2 = new ListNode(2, l1);
	ListNode* l3 = new ListNode(1, l2);

	ListNode* q1 = new ListNode(4);
	ListNode* q2 = new ListNode(3, q1);
	ListNode* q3 = new ListNode(1, q2);

	ListNode* n1 = sln.mergeTwoLists(l3, q3);
	sln.Lprint(n1);

	l1 = nullptr;
	q1 = nullptr;
	ListNode* n2 = sln.mergeTwoLists(l1, q1);
	sln.Lprint(n2);

	l1 = nullptr;
	q1 = new ListNode(0);
	ListNode* n3 = sln.mergeTwoLists(l1, q1);
	sln.Lprint(n3);
}

void test07()
{
	Solution sln;
	vector<string>strs1 = { "flower","flow","flight" };
	string res1 = sln.longestCommonPrefix(strs1);
	vector<string>strs2 = { "dog","racecar","car" };
	string res2 = sln.longestCommonPrefix(strs2);
	cout << res1 << endl;
	cout << res2 << endl;
}

void test08()
{
	Solution sln;
	string s1 = { "III" };
	int res1 = sln.romanToInt(s1);
	cout << res1 << endl;

	string s2 = { "IV" };
	int res2 = sln.romanToInt(s2);
	cout << res2 << endl;

	string s3 = { "IX" };
	int res3 = sln.romanToInt(s3);
	cout << res3 << endl;

	string s4 = { "LVIII" };
	int res4 = sln.romanToInt(s4);
	cout << res4 << endl;

	string s5 = { "MCMXCIV" };
	int res5 = sln.romanToInt(s5);
	cout << res5 << endl;
}

void test09()
{
	Solution sln;
	vector<int>nums1 = { 0,1,0,3,12 };
	sln.moveZeroes(nums1);
	sln.Tprint(nums1);

	vector<int>nums2 = { 0 };
	sln.moveZeroes(nums2);
	sln.Tprint(nums2);


}

void test10()
{
	Solution sln;
	int n1 = 2;
	cout << sln.climbStairs(n1) << endl;
	int n2 = 45;
	cout << sln.climbStairs(n2) << endl;

}

void test11()
{
	Solution sln;
	vector<int>prices1 = { 7,1,5,3,6,4 };
	vector<int>prices2 = { 7,6,4,3,1 };
	cout << sln.maxProfit(prices1) << endl;
	cout << sln.maxProfit(prices2) << endl;
}

void test12()
{
	Solution sln;
	vector<int>nums1 = { 1,2,3,0,0,0 };
	vector<int>nums2 = { 2,5,6 };
	sln.merge(nums1, 3, nums2, 3);
	sln.Tprint(nums1);

	vector<int>nums3 = { 1 };
	vector<int>nums4 = {  };
	sln.merge(nums3, 1, nums4, 0);
	sln.Tprint(nums3);

	vector<int>nums5 = { 0 };
	vector<int>nums6 = { 1 };
	sln.merge(nums5, 0, nums6, 1);
	sln.Tprint(nums5);

}

void test13()
{
	Solution sln;
	vector<int>nums1 = { 1,2,3 };
	vector<int>nums2 = { 9 };
	vector<int>nums3 = { 1,0,9 };
	vector<int>res1 = sln.plusOne(nums1);
	vector<int>res2 = sln.plusOne(nums2);
	vector<int>res3 = sln.plusOne(nums3);
	sln.Tprint(res1);
	sln.Tprint(res2);
	sln.Tprint(res3);
}

void test14()
{
	Solution sln;
	TreeNode* n1 = new TreeNode(15);
	TreeNode* n2 = new TreeNode(7);
	TreeNode* n3 = new TreeNode(20, n1, n2);
	TreeNode* n4 = new TreeNode(9);
	TreeNode* n5 = new TreeNode(3, n4, n3);
	cout << sln.maxDepth(n5) << endl;

}

void test15()
{
	Solution sln;
	ListNode* n1 = new ListNode(-4);
	ListNode* n2 = new ListNode(0, n1);
	ListNode* n3 = new ListNode(2, n2);
	ListNode* n4 = new ListNode(3, n3);
	n1->next = n3;
	cout << sln.hasCycle(n4) << endl;
	ListNode* N1 = new ListNode(2);
	ListNode* N2 = new ListNode(1, N1);
	N1->next = N2;
	cout << sln.hasCycle(N2) << endl;
	ListNode* Q = new ListNode(1);
	cout << sln.hasCycle(Q) << endl;
}

void test16()
{
	Solution sln;
	vector<int>nums1 = { -1,0,3,5,9,12 };
	cout << sln.search(nums1, 9) << endl;
	vector<int>nums2 = { -1,0,3,5,9,12 };
	cout << sln.search(nums2, 2) << endl;

}

void test17()
{
	Solution sln;
	string s1 = "Hello World";
	string s2 = "   fly me   to   the moon  ";
	string s3 = "luffy";
	cout << sln.lengthOfLastWord(s1) << endl;
	cout << sln.lengthOfLastWord(s2) << endl;
	cout << sln.lengthOfLastWord(s3) << endl;

}

void test18()
{
	Solution sln;
	vector<int>nums = { 2, 3, 1, 0, 2, 5, 3 };
	cout << sln.findRepeatNumber(nums) << endl;
}

void test19()
{
	Solution sln;
	TreeNode* n1 = new TreeNode(3);
	TreeNode* n2 = new TreeNode(4);
	TreeNode* n3 = new TreeNode(4);
	TreeNode* n4 = new TreeNode(3);
	TreeNode* n5 = new TreeNode(2, n1, n2);
	TreeNode* n6 = new TreeNode(2, n3, n4);
	TreeNode* n7= new TreeNode(1, n5, n6);
	cout << sln.isSymmetric(n7) << endl;
	TreeNode* N1 = new TreeNode(3);
	TreeNode* N2 = new TreeNode(3);
	TreeNode* N3 = new TreeNode(2,nullptr,N1);
	TreeNode* N4 = new TreeNode(2,nullptr,N2);
	TreeNode* N5 = new TreeNode(1, N3, N4);
	cout << sln.isSymmetric(N5) << endl;

}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	// 
	// 0306
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
	//test18();
	test19();
	system("pause");
	return 0;

}