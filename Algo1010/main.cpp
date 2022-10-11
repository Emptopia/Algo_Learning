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

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return 0;
}