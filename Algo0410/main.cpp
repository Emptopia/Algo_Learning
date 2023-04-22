#include"Solution.h"
#include<iostream>
using namespace std;



void test01()
{
	Solution sln;
	TreeNode* n1 = new TreeNode(7);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(1);
	TreeNode* n4 = new TreeNode(11,n1,n2);
	TreeNode* n5 = new TreeNode(13);
	TreeNode* n6 = new TreeNode(4, nullptr, n3);
	TreeNode* n7 = new TreeNode(4, n4, nullptr);
	TreeNode* n8 = new TreeNode(8, n5, n6);
	TreeNode* n9 = new TreeNode(5, n7, n8);
	cout << sln.hasPathSum(n9, 22) << endl;




}

void test02()
{
	CQueue* cq = new CQueue();
	cq->appendTail(3);
	cout << cq->deleteHead() << endl;
	cout << cq->deleteHead() << endl;
	cout << cq->deleteHead() << endl;

}

void test03()
{
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = "race a car";
	string s3 = "0p";
	Solution sln;
	cout << sln.isPalindrome(s1) << endl;
	cout << sln.isPalindrome(s2) << endl;
	cout << sln.isPalindrome(s3) << endl;
}

void test04()
{
	Solution sln;
	string ransomNote = "aa";
	string magazine = "aab";
	cout << sln.canConstruct(ransomNote, magazine) << endl;
}

void test05()
{
	Solution sln;
	string a = "1010";
	string b = "1011";
	cout << sln.addBinary(a, b) << endl;
}

void test06()
{
	Solution sln;
	vector<int>n1 = { 1,2,2,1 };
	vector<int>n2 = { 2,2 };
	vector<int>n3 = { 4,9,5 };
	vector<int>n4 = { 9,4,9,8,4 };
	vector<int>res1 = sln.intersection(n1, n2);
	vector<int>res2 = sln.intersection(n3, n4);
	sln.Tprint(res1);
	sln.Tprint(res2);
}

void test07()
{
	Solution sln;
	cout << sln.fib(5) << endl;
}


void test08()
{
	Solution sln;
	cout << sln.isHappy(19) << endl;
	cout << sln.isHappy(2) << endl;
}

void test09()
{
	Solution sln;
	string s1 = "abc";
	string t1 = "ahbgdc";
	string s2 = "axc";
	string t2 = "ahbgdc";
	cout << sln.isSubsequence(s1, t1) << endl;
	cout << sln.isSubsequence(s2, t2) << endl;

}

void test10()
{
	Solution sln;
	TreeNode* t1 = new TreeNode(3);
	TreeNode* t2 = new TreeNode(2, t1, nullptr);
	TreeNode* t3 = new TreeNode(1, nullptr, t2);
	vector<int>res = sln.postorderTraversal(t3);
	sln.Tprint(res);


}

void test11()
{
	Solution sln;
	vector<int>nums = { 5,7,7,8,8,10 };
	int target = 8;
	cout << sln.search(nums, target) << endl;
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
	test11();
	return 0;
}