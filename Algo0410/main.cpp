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

int main()
{
	test01();
	test02();
	return 0;
}