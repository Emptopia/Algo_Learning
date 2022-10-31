#include<iostream>
using namespace std;
#include<vector>
#include"Solution.h"

void test01()
{
	Solution sln;
	int n = 3;
	int res = sln.sumNums(n);
	cout << res << endl;

}

void test02()
{
	Solution sln;
	TreeNode* N1 = new TreeNode(3);
	TreeNode* N2 = new TreeNode(5);
	TreeNode* N3 = new TreeNode(0);
	TreeNode* N4 = new TreeNode(4, N1, N2);
	TreeNode* N5 = new TreeNode(7);
	TreeNode* N6 = new TreeNode(9);
	TreeNode* N7 = new TreeNode(2, N3, N4);
	TreeNode* N8 = new TreeNode(8, N5, N6);
	TreeNode* N9 = new TreeNode(6, N7, N8);
	cout << sln.lowestCommonAncestor1(N9, N7, N8)->val << endl;
	cout << sln.lowestCommonAncestor1(N9, N7, N4)->val << endl;
}

void test03()
{
	Solution sln;
	TreeNode* N1 = new TreeNode(7);
	TreeNode* N2 = new TreeNode(4);
	TreeNode* N3 = new TreeNode(6);
	TreeNode* N4 = new TreeNode(2, N1, N2);
	TreeNode* N5 = new TreeNode(0);
	TreeNode* N6 = new TreeNode(8);
	TreeNode* N7 = new TreeNode(5, N3, N4);
	TreeNode* N8 = new TreeNode(1, N5, N6);
	TreeNode* N9 = new TreeNode(3, N7, N8);
	cout << sln.lowestCommonAncestor(N9, N7, N8)->val << endl;//3
	cout << sln.lowestCommonAncestor(N9, N2, N7)->val << endl;//5

}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;

}