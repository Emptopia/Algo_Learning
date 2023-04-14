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

int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}