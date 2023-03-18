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

void test04()
{
	vector<int>preorder = { 3,9,20,15,7 };
	vector<int>inorder = { 9,3,15,20,7 };
	Solution sln;
	TreeNode* root = sln.buildTree(preorder, inorder);
	cout << root->val << endl;


}

void test05()
{
	Solution sln;
	double x = 2.10000;
	int n = 3;
	double res = sln.myPow(x, n);
	cout << res << endl;

}

void test06()
{
	Solution sln;
	vector<int>postorder = { 1,3,2,6,5 };
	cout << sln.verifyPostorder(postorder) << endl;
}

void test07()
{
	Solution sln;
	uint32_t n = 00000000000000000000000000001011;
	int res = sln.hammingWeight(n);
	cout << res << endl;
}

void test08()
{
	Solution sln;
	int a = 1;
	int b = 1;
	int res = sln.add(a, b);
	cout << res << endl;
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
	test08();
	system("pause");
	return 0;

}