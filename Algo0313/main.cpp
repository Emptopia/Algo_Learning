#include<iostream>
using namespace std;
#include"Solution.h"

void test01()
{
	Solution sln;
	TreeNode* n1 = new TreeNode(3);
	TreeNode* n2 = new TreeNode(2, n1, nullptr);
	TreeNode* n3 = new TreeNode(1, nullptr, n2);
	vector<int>res1 = sln.inorderTraversal(n3);
	sln.Tprint(res1);
}

void test02()
{
	Solution sln;
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(3);
	TreeNode* n3 = new TreeNode(6);
	TreeNode* n4 = new TreeNode(9);
	TreeNode* n5 = new TreeNode(2, n1, n2);
	TreeNode* n6 = new TreeNode(7, n3, n4);
	TreeNode* n7 = new TreeNode(4, n5, n6);
	sln.invertTree(n7);
	sln.TreePrint(n7);

	TreeNode* N1 = new TreeNode(1);
	TreeNode* N2 = new TreeNode(3);
	TreeNode* N3 = new TreeNode(2, N1, N2);
	sln.invertTree(N3);
	sln.TreePrint(N3);

	TreeNode* R = nullptr;
	sln.invertTree(R);
	sln.TreePrint(R);
}

void test03()
{
	vector<int>nums1 = { 2,2,1 };
	vector<int>nums2 = { 4,1,2,1,2 };
	vector<int>nums3 = { 1 };
	Solution sln;
	cout << sln.singleNumber(nums1) << endl;
	cout << sln.singleNumber(nums2) << endl;
	cout << sln.singleNumber(nums3) << endl;

}

void test04()
{
	Solution sln;
	TreeNode* n1 = new TreeNode(15);
	TreeNode* n2 = new TreeNode(7);
	TreeNode* n3 = new TreeNode(9);
	TreeNode* n4 = new TreeNode(20, n1, n2);
	TreeNode* n5 = new TreeNode(3, n3, n4);
	cout << sln.minDepth(n5) << endl;

	TreeNode* N1 = new TreeNode(6);
	TreeNode* N2 = new TreeNode(5, nullptr, N1);
	TreeNode* N3 = new TreeNode(4, nullptr, N2);
	TreeNode* N4 = new TreeNode(3, nullptr, N3);
	TreeNode* N5 = new TreeNode(2, nullptr, N4);
	cout << sln.minDepth(N5) << endl;

}

void test05()
{
	Solution sln;
	ListNode* a1 = new ListNode(5);
	ListNode* a2 = new ListNode(4,a1);
	ListNode* a3 = new ListNode(8,a2);
	ListNode* b1 = new ListNode(1, a3);
	ListNode* b2 = new ListNode(4, b1);
	ListNode* c1 = new ListNode(1, a3);
	ListNode* c2 = new ListNode(6, c1);
	ListNode* c3 = new ListNode(5, c2);
	ListNode* ins = sln.getIntersectionNode(b2, c3);
	sln.ListPrint(ins);
}

void test06()
{
	Solution sln;
	vector<int>nums1 = { 3,2,3 };
	vector<int>nums2 = { 2,2,1,1,1,2,2 };
	cout << sln.majorityElement(nums1) << endl;
	cout << sln.majorityElement(nums2) << endl;

}

void test07()
{
	Solution sln;
	cout << sln.mySqrt(1) << endl;
	cout << sln.mySqrt(26) << endl;
	cout << sln.mySqrt(INT_MAX) << endl;

}

void test08()
{
	Solution sln;
	vector<char>s1 = { 'h','e','l','l','o' };
	vector<char>s2 = { 'H','a','n','n','a','h' };
	sln.reverseString(s1);
	sln.reverseString(s2);
	sln.Tprint(s1);
	sln.Tprint(s2);
}

void test09()
{
	Solution sln;
	string s = "We are happy.";
	cout << sln.replaceSpace(s) << endl;

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
	test09();
	system("pause");
	return 0;

}