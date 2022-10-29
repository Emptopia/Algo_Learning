#include<iostream>
using namespace std;
#include<vector>
#include"Solution.h"
#include"MedianFinder.h"
void test01()
{
	vector<int>nums = { 3,2,1 };
	int k = 2;
	Solution sln;
	vector<int>res = sln.getLeastNumbers(nums, k);
	sln.Tprint(res);
}

void test02()
{
	MedianFinder* obj = new MedianFinder();
	obj->addNum(1);
	obj->addNum(2);
	double n1 = obj->findMedian();
	cout << n1 << endl;
	obj->addNum(3);
	double n2 = obj->findMedian();
	cout << n2 << endl;
}

void test03()
{
	Solution sln;
	TreeNode* N1 = new TreeNode(15);
	TreeNode* N2 = new TreeNode(7);
	TreeNode* N3 = new TreeNode(9);
	TreeNode* N4 = new TreeNode(20, N1, N2);
	TreeNode* N5 = new TreeNode(3, N3, N4);
	int res = sln.maxDepth(N5);
	cout << res << endl;

}

void test04()
{
	Solution sln;
	//TreeNode* N1 = new TreeNode(15);
	//TreeNode* N2 = new TreeNode(7);
	//TreeNode* N3 = new TreeNode(9);
	//TreeNode* N4 = new TreeNode(20, N1, N2);
	//TreeNode* N5 = new TreeNode(3, N3, N4);
	//bool res = sln.isBalanced(N5);
	TreeNode* N1 = new TreeNode(4);
	TreeNode* N2 = new TreeNode(4);
	TreeNode* N3 = new TreeNode(3, N1, N2);
	TreeNode* N4 = new TreeNode(3);
	TreeNode* N5 = new TreeNode(2, N3, N4);
	TreeNode* N6 = new TreeNode(2);
	TreeNode* N7 = new TreeNode(1, N5, N6);
	bool res = sln.isBalanced(N7);


	cout << res << endl;

}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return 0;
}